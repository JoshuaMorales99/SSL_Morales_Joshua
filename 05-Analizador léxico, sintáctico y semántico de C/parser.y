%{

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#define YYDEBUG 1

FILE* yyin;
detalleParametros *ListaParametros = NULL;
detalleSentencia *ListaSentencias = NULL;
detalleTablaDeSimbolos * TablaDeSimbolos = NULL;

int contadorParametros = 0;
int nroLineaAnterior = 1;
char tipo[20];

int yylex();
int yyerror (char *s);

int yywrap(){
  return(1);
}

%}


%token CONSTANTE_OCTAL CONSTANTE_DECIMAL CONSTANTE_HEXADECIMAL
%token CONSTANTE_REAL 
%token CONSTANTE_CARACTER
%token OR AND
%token IGUALIGUAL DIFERENTE
%token MAYORIGUAL
%token MENORIGUAL
%token MASIGUAL MENOSIGUAL PORIGUAL DIVISIONGUAL
%token MASMAS MENOSMENOS
%token FLECHA
%token AUTO TYPEDEF STATIC REGISTER EXTERN ENUM
%token SIZEOF
%token UNION STRUCT
%token GOTO RETURN CONTINUE BREAK
%token VOLATILE CONST
%token WHILE DO FOR
%token IF ELSE SWITCH CASE DEFAULT
%token VOID
%token CHAR DOUBLE FLOAT INT LONG SHORT SIGNED UNSIGNED
%token IDENTIFICADOR
%token LITERAL_CADENA
%token COMENTARIO_UNA_LINEA COMENTARIO_VARIAS_LINEAS

%start input

%union{
  struct {
    char* cadena;
    int entero;
    int esNumerico;
  } myStruct;
}


%%

input:                    /* vacio */
                        | input line                                            {nroLineaAnterior = $<myStruct.entero>2}
;

line:                     sentencia
                        | declaracion
                        | prototipo ';'                                         {ListaParametros = NULL;contadorParametros=0;}
                        | funciones                                             {ListaParametros = NULL;contadorParametros=0;}
                        | noC
                        | error ';'                                             {printf("Error sintactico en linea %d\n", $<myStruct.entero>1);}
;

noC:                      COMENTARIO_UNA_LINEA                                  
                        | COMENTARIO_VARIAS_LINEAS                              
;

/*============================== FUNCIONES ==================================*/

prototipo:                VOID IDENTIFICADOR '(' parametrosPrototipo ')'        {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, "void", 'F', ListaParametros, contadorParametros);}
                        | VOID IDENTIFICADOR '(' ')'                            {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, "void", 'F', ListaParametros, contadorParametros);}
                        | tipoDeDato IDENTIFICADOR '(' parametrosPrototipo ')'  {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'F', ListaParametros, contadorParametros);}
                        | tipoDeDato IDENTIFICADOR '(' ')'                      {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'F', ListaParametros, contadorParametros);}
;

parametrosPrototipo:      tipoDeDato {ListaParametros=agregarListaParametros (ListaParametros, NULL, tipo);contadorParametros++;}
                        | tipoDeDato ',' {ListaParametros=agregarListaParametros (ListaParametros, NULL, tipo);contadorParametros++;} parametrosPrototipo
;

funciones:                VOID IDENTIFICADOR '(' ')' sentCompuesta                          {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, "void", 'F', ListaParametros, contadorParametros);}
                        | VOID IDENTIFICADOR '(' parametrosFuncion ')' sentCompuesta        {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, "void", 'F', ListaParametros, contadorParametros);}
                        | tipoDeDato IDENTIFICADOR '(' ')' sentCompuesta                    {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'F', ListaParametros, contadorParametros);}
                        | tipoDeDato IDENTIFICADOR '(' parametrosFuncion ')' sentCompuesta  {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'F', ListaParametros, contadorParametros);}    
;

parametrosFuncion:        tipoDeDato IDENTIFICADOR {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, tipo, 'V', ListaParametros, 0);ListaParametros=agregarListaParametros (ListaParametros, $<myStruct.cadena>2, tipo);contadorParametros++;}
                        | tipoDeDato IDENTIFICADOR ',' {TablaDeSimbolos=agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, tipo, 'V', ListaParametros, 0);ListaParametros=agregarListaParametros (ListaParametros, $<myStruct.cadena>2, tipo);contadorParametros++;} parametrosFuncion
;


/*==============================================SENTENCIAS===========================================*/
/* conflictos: 1 desplazamiento/reducción (En sentElse)*/

sentencia:                sentExpresion                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia de Expresion",$<myStruct.entero>1);}
                        | sentCompuesta                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Inicio sentencia Compuesta",$<myStruct.entero>1);}
                        | sentSeleccion                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Seleccion",$<myStruct.entero>1);}
                        | sentIteracion                                         {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Iteracion",$<myStruct.entero>1);}
                        | sentEtiquetado                                        {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Etiquetado",$<myStruct.entero>1);}
                        | sentSalto                                             {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Salto",$<myStruct.entero>1);}
;

sentExpresion:            expresion ';'
                        | ';'                                                   {ListaSentencias=agregarListaSentencias(ListaSentencias,"Sentencia Vacia",$<myStruct.entero>1);}
;

sentCompuesta:            '{' listaSentencias '}'                               {ListaSentencias=agregarListaSentencias(ListaSentencias,"Fin sentencia Compuesta",$<myStruct.entero>3);}
                        | '{' '}'                                               {ListaSentencias=agregarListaSentencias(ListaSentencias,"Fin sentencia Compuesta",$<myStruct.entero>2);}
;

listaSentencias:          line
                        | listaSentencias line
;

sentSeleccion:            IF '(' expresion ')' sentencia sentElse                        
                        | SWITCH '(' expresion ')' sentencia                    
;

sentElse:                 /* vacio */                                                                                   
                        | ELSE sentencia                                        
;

sentIteracion:            WHILE '(' expresion ')' sentencia                     
                        | DO line WHILE '(' expresion ')' ';'                   
                        | FOR '(' cuerpoFor ')' sentencia                       
;

cuerpoFor:                declaracionFor ';' expresion ';' expresion
                        | ';' expresion ';' expresion
                        | declaracionFor ';' ';' expresion
                        | declaracionFor ';' expresion ';'
                        | ';' ';' expresion
                        | declaracionFor ';' ';'
                        | ';' ';'
;

declaracionFor:           tipoDeDato variasVariables
                        | variasVariables
;

sentEtiquetado:           CASE constante ':' sentencia
	                      | DEFAULT ':' sentencia
	                      | IDENTIFICADOR ':' sentencia
;

sentSalto:                BREAK ';'
                        | CONTINUE ';'
                        | RETURN expresion ';'
                        | RETURN ';'
                        | GOTO ';'
;

/*=========================================DECLARACIONES===============================================*/
/* No hay conflictos */

declaracion:              espAlmacenamiento tipoDeDato IDENTIFICADOR ';'
                        | espAlmacenamiento calificadorTipo tipoDeDato IDENTIFICADOR ';'
                        | espAlmacenamiento espStructUnion IDENTIFICADOR ';'
                        | espAlmacenamiento espEnum IDENTIFICADOR ';'
                        | espDeclaracion
;

espDeclaracion:           calificadorTipo tipoDeDato {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, tipo); strcpy(tipo, $<myStruct.cadena>1);} variasVariables ';'
                        | calificadorTipo espSigno {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, $<myStruct.cadena>2); strcpy(tipo, $<myStruct.cadena>1);} variasVariables ';'
                        | declaraciones ';'
;

variasVariables:          inicializacion
                        | variasVariables inicializacion
;

inicializacion:           IDENTIFICADOR ',' {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, tipo, 'V', ListaParametros, contadorParametros);} inicializacion
		                    | IDENTIFICADOR '=' expresion ',' {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, tipo, 'V', ListaParametros, contadorParametros);if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");} inicializacion
		                    | IDENTIFICADOR '=' expresion {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, tipo, 'V', ListaParametros, contadorParametros);if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | IDENTIFICADOR {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, tipo, 'V', ListaParametros, contadorParametros);}
;

espAlmacenamiento:        TYPEDEF
                        | STATIC
                        | AUTO
                        | REGISTER
                        | EXTERN
;

declaraciones:            tipoDeDato variasVariables
                        | espSigno variasVariables
                        | espStructUnion
                        | espEnum
;

espSigno:                 SIGNED tipoDeDato {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, tipo); strcpy(tipo, $<myStruct.cadena>1);}
                        | SIGNED {strcpy(tipo, $<myStruct.cadena>1);}
                        | UNSIGNED tipoDeDato {strcat($<myStruct.cadena>1, " "); strcat($<myStruct.cadena>1, tipo); strcpy(tipo, $<myStruct.cadena>1);}
                        | UNSIGNED {strcpy(tipo, $<myStruct.cadena>1);}
;

tipoDeDato:               CHAR                                                  {strcpy(tipo, $<myStruct.cadena>1);}
	                      | DOUBLE                                                {strcpy(tipo, $<myStruct.cadena>1);}
	                      | FLOAT                                                 {strcpy(tipo, $<myStruct.cadena>1);}
	                      | INT                                                   {strcpy(tipo, $<myStruct.cadena>1);}
	                      | LONG                                                  {strcpy(tipo, $<myStruct.cadena>1);}
	                      | SHORT                                                 {strcpy(tipo, $<myStruct.cadena>1);}
;

calificadorTipo:          CONST                                                 {strcpy(tipo, $<myStruct.cadena>1);}
                        | VOLATILE                                              {strcpy(tipo, $<myStruct.cadena>1);}
;

espStructUnion:           STRUCT IDENTIFICADOR '{' declaracionesStruct '}'      {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'V', ListaParametros, contadorParametros);}
                        | STRUCT '{' declaracionesStruct '}'
                        | UNION IDENTIFICADOR '{' declaracionesStruct '}'       {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'V', ListaParametros, contadorParametros);}
                        | UNION '{' declaracionesStruct '}'
;

declaracionesStruct:      tipoDeDato variasVariablesStruct ';'
                        | tipoDeDato variasVariablesStruct ';' declaracionesStruct
;

variasVariablesStruct:    inicializacionStruct
                        | variasVariablesStruct inicializacionStruct
;

inicializacionStruct:     IDENTIFICADOR ',' {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, tipo, 'V', ListaParametros, contadorParametros);} inicializacionStruct
		                    | IDENTIFICADOR {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, tipo, 'V', ListaParametros, contadorParametros);}
;

espEnum:                  ENUM IDENTIFICADOR {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>2, $<myStruct.cadena>1, 'V', ListaParametros, contadorParametros);} '{' listaIdentificadores '}'       
;

listaIdentificadores:     IDENTIFICADOR ',' {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, "int", 'V', ListaParametros, contadorParametros);} listaIdentificadores
                        | IDENTIFICADOR {TablaDeSimbolos= agregarAListaDeSimbolos(TablaDeSimbolos, $<myStruct.cadena>1, "int", 'V', ListaParametros, contadorParametros);}
;

/*=============================================EXPRESIONES=============================================*/
/* No hay conflictos */

expresion:                expAsignacion
;

expAsignacion:            expCondicional
                        | expUnaria operAsig expAsignacion
;

operAsig:                 '='
                        | MASIGUAL
                        | MENOSIGUAL
                        | PORIGUAL
                        | DIVISIONGUAL
;

expCondicional:           expOr
                        | expOr '?' expresion ':' expCondicional
;

expOr:                    expAnd
                        | expAnd OR expOr
;

expAnd:                   expIgualdad
                        | expIgualdad AND expAnd
;

expIgualdad:              expRelacional
                        | expRelacional IGUALIGUAL expIgualdad
                        | expRelacional DIFERENTE expIgualdad
;

expRelacional:            expAditiva
                        | expAditiva '<' expRelacional  {if($<myStruct.esNumerico>1 != $<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | expAditiva '>' expRelacional  {if($<myStruct.esNumerico>1 != $<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | expAditiva MAYORIGUAL expRelacional {if($<myStruct.esNumerico>1 != $<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | expAditiva MENORIGUAL expRelacional {if($<myStruct.esNumerico>1 != $<myStruct.esNumerico>3) printf("\n\tError\n");}
;

expAditiva:               expMultiplicativa
                        | expMultiplicativa '+' expAditiva  {if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | expMultiplicativa '-' expAditiva  {if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");}
;

expMultiplicativa:        expUnaria
                        | expUnaria '*' expMultiplicativa {if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | expUnaria '/' expMultiplicativa {if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");}
                        | expUnaria '%' expMultiplicativa {if(!$<myStruct.esNumerico>1 || !$<myStruct.esNumerico>3) printf("\n\tError\n");}
;

expUnaria:                expSufijo
                        | MASMAS expUnaria  {if(!$<myStruct.esNumerico>2) printf("\n\tError\n");}
                        | MENOSMENOS expUnaria  {if(!$<myStruct.esNumerico>2) printf("\n\tError\n");}
                        | operUnario expUnaria
                        | SIZEOF expUnaria  {$<myStruct.esNumerico>$ = 1;}
;

operUnario:               '&'
                        | '*'
                        | '+'
                        | '-'
                        | '!'
;

expSufijo:                expPrimaria
                        | expSufijo '[' expresion ']'
                        | expSufijo '(' listaArgumentos ')'
                        | expSufijo '(' ')'
                        | expSufijo '.' IDENTIFICADOR
                        | expSufijo FLECHA IDENTIFICADOR
                        | expSufijo MASMAS  {if(!$<myStruct.esNumerico>1) printf("\n\tError\n");}
                        | expSufijo MENOSMENOS  {if(!$<myStruct.esNumerico>1) printf("\n\tError\n");}
;

listaArgumentos:          expAsignacion
                        | expAsignacion ',' listaArgumentos
;

expPrimaria:              IDENTIFICADOR {$<myStruct.esNumerico>$ = buscarVariable(TablaDeSimbolos, $<myStruct.cadena>$)}
                        | constante
                        | LITERAL_CADENA
                        | '(' expresion ')'
;

constante:                constanteEntera
                        | CONSTANTE_CARACTER
                        | CONSTANTE_REAL
;

constanteEntera:          CONSTANTE_OCTAL
                        | CONSTANTE_DECIMAL
                        | CONSTANTE_HEXADECIMAL
;

%%

/* Llamada por yyparse ante un error */
int yyerror (char *s) {
  //printf ("%s\n", s);
}


/* Main */
int main (){

  #ifdef BISON_DEBUG
    yydebug = 1;
  #endif

  yyin = fopen("entrada.c","r");
  yyparse();

  fclose(yyin);

  recorrerListaSentencias(ListaSentencias);
  recorrerTablaDeSimbolos(TablaDeSimbolos);
  
  getch();

return 0;
}