%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    int yylex();
    int yyerror (char *);
    int yywrap(){
        return(1);
    }

%}

%union{
    int ival;
    float fval;
    char * cadena;
}

%token CONSTANTE_OCTAL CONSTANTE_DECIMAL CONSTANTE_HEXADECIMAL
%token CONSTANTE_REAL 
%token CONSTANTE_CARACTER
%token OR AND
%token IGUALIGUAL DIFERENTE
%token MAYORIGUAL MENORIGUAL
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

%start sentencia

%%

noC:                      COMENTARIO_UNA_LINEA
                        | COMENTARIO_VARIAS_LINEAS
;

expresion:                expAsignacion
;

expAsignacion:            expCondicional
                        | expUnaria operAsignacion expAsignacion
;

operAsignacion:           '='
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
                        | expAditiva MAYORIGUAL expRelacional
                        | expAditiva MENORIGUAL expRelacional
                        | expAditiva '<' expRelacional
                        | expAditiva '>' expRelacional
;

expAditiva:               expMultiplicativa
                        | expMultiplicativa '+' expAditiva                                  {printf("Suma");}
                        | expMultiplicativa '-' expAditiva
;

expMultiplicativa:        expUnaria
                        | expUnaria '*' expMultiplicativa
                        | expUnaria '/' expMultiplicativa
                        | expUnaria '%' expMultiplicativa
;

expUnaria:                expSufijo
                        | MASMAS expUnaria
                        | MENOSMENOS expUnaria
                        | operUnario expUnaria
                        | SIZEOF '(' espTipo ')'
                        | SIZEOF expUnaria
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
                        | expSufijo MASMAS
                        | expSufijo MENOSMENOS
;

listaArgumentos:          expAsignacion
                        | expAsignacion ',' listaArgumentos
;

expPrimaria:              IDENTIFICADOR
                        | constante
                        | LITERAL_CADENA
                        | '(' expresion ')'
;

sentencia:                sentCompuesta
                        | sentExpresion
                        | sentSeleccion
                        | sentIteracion
                        | sentSalto
                        | noC
;

sentCompuesta:            '{' listaDeclaraciones listaSentencias '}'
                        | '{' listaDeclaraciones '}'
                        | '{' listaSentencias '}'
                        | '{' '}'
;

listaDeclaraciones:       declaracion
                        | declaracion listaDeclaraciones
;

declaracion:              espDeclaracion listaDeclaradores
                        | espDeclaracion
;

espDeclaracion:           espAlmacenamiento espDeclaracion
                        | espAlmacenamiento
                        | espTipo espDeclaracion
                        | espTipo
                        | calificadorTipo espDeclaracion
                        | calificadorTipo
;

listaDeclaradores:        declarador
                        | declarador ',' listaDeclaradores
;

declarador:               decla
                        | decla expAsignacion
;

espAlmacenamiento:        TYPEDEF
                        | STATIC
                        | AUTO
                        | REGISTER
                        | EXTERN
;

espTipo:                  VOID
                        | CHAR
                        | SHORT
                        | INT
                        | LONG
                        | FLOAT
                        | DOUBLE
                        | SIGNED
                        | UNSIGNED
                        | espStructUnion
                        | IDENTIFICADOR
;

calificadorTipo:          CONST
                        | VOLATILE
;

espStructUnion:           structUnion IDENTIFICADOR '{' listaStruct '}'
                        | structUnion '{' listaStruct '}'
                        | structUnion IDENTIFICADOR
;

structUnion:              STRUCT
                        | UNION
;

listaStruct:              declaracionStruct
                        | declaracionStruct listaStruct
;

declaracionStruct:        listaCalificadores declaradoresStruct ';'
;

listaCalificadores:       espTipo listaCalificadores
                        | espTipo
                        | calificadorTipo listaCalificadores
                        | calificadorTipo
;

declaradoresStruct:       decla
                        | declaradoresStruct ',' decla
;

decla:                    puntero declaradorDirecto
                        | declaradorDirecto
;

puntero:                  '*' listaCalificadoresTipo
                        | '*'
                        | '*' listaCalificadoresTipo puntero
                        | '*' puntero
;

listaCalificadoresTipo:   calificadorTipo
                        | calificadorTipo listaCalificadoresTipo
;

declaradorDirecto:        IDENTIFICADOR
                        | '(' decla ')'
                        | declaradorDirecto '[' constante ']'
                        | declaradorDirecto '[' ']'
;

listaSentencias:          listaSentencias sentencia
                        | sentencia
;

sentExpresion:            expresion ';'
                        | ';'
;

sentSeleccion:            IF '(' expresion ')' sentencia ELSE sentencia                     {printf("if con else");}
                        | IF '(' expresion ')' sentencia                                    {printf("if sin else");}
                        | SWITCH '(' expresion ')' sentSwitch
;

sentSwitch:               '{' CASE constante ':' sentencia DEFAULT ':' sentencia '}'
	                    | '{' CASE constante ':' sentencia '}'
	                    | '{' DEFAULT ':' sentencia '}'
	                    | '{' '}'
;

sentIteracion:            WHILE '(' expresion ')' sentencia
                        | DO sentencia WHILE '(' expresion ')' ';'
                        | FOR '(' cuerpoFor ')' sentencia
;

cuerpoFor:                expresion ';' expresion ';' expresion
                        | ';' expresion ';' expresion
                        | expresion ';' ';' expresion
                        | expresion ';' expresion ';'
                        | ';' ';' expresion
                        | expresion ';' ';'
                        | ';' ';' ';'
;

sentSalto:                BREAK ';'
                        | CONTINUE ';'
                        | RETURN expresion ';'
                        | RETURN ';'
                        | GOTO ';'
;

constante:                constanteEntera
                        | CONSTANTE_CARACTER                                                {printf("Caracter\n");}
                        | CONSTANTE_REAL                                                    {printf("Real\n");}
;

constanteEntera:          CONSTANTE_OCTAL                                                   {printf("Octal\n");}
                        | CONSTANTE_DECIMAL                                                 {printf("Decimal\n");}
                        | CONSTANTE_HEXADECIMAL                                             {printf("Hexadecimal\n");}
;

%%
int yyerror(char * mensaje){
    printf("Error: %s\n", mensaje);
}

int main(){

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif

    printf("> ");
    
return yyparse();
}