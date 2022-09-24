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
    int tipoNumerico;
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

%start expresion

%%
/* PARA COMENTARIO, DIRECTIVAS Y DEMÁS
noC:                      COMENTARIO_UNA_LINEA
                        | COMENTARIO_VARIAS_LINEAS
;
*/

expresion:                expAsignacion
;

expAsignacion:            expCondicional
                        | IDENTIFICADOR '=' expAsignacion                                   {}
                        | IDENTIFICADOR MASIGUAL expAsignacion                              {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | IDENTIFICADOR MENOSIGUAL expAsignacion                            {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | IDENTIFICADOR PORIGUAL expAsignacion                              {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | IDENTIFICADOR DIVISIONGUAL expAsignacion                          {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
;

expCondicional:           expOr
                        | expOr '?' expresion ':' expCondicional
;

expOr:                    expAnd
                        | expAnd OR expOr                                                   {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
;

expAnd:                   expIgualdad
                        | expIgualdad AND expAnd                                            {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
;

expIgualdad:              expRelacional
                        | expRelacional IGUALIGUAL expIgualdad                              {if($<tipoNumerico>1 == $<tipoNumerico>3) $<tipoNumerico>$ = 1; else printf("Error: Tipo incompatible\n");}
                        | expRelacional DIFERENTE expIgualdad                               {if($<tipoNumerico>1 == $<tipoNumerico>3) $<tipoNumerico>$ = 1; else printf("Error: Tipo incompatible\n");}
;

expRelacional:            expAditiva
                        | expAditiva MAYORIGUAL expRelacional                               {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | expAditiva MENORIGUAL expRelacional                               {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | expAditiva '<' expRelacional                                      {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | expAditiva '>' expRelacional                                      {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
;

expAditiva:               expMultiplicativa
                        | expMultiplicativa '+' expAditiva                                  {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | expMultiplicativa '-' expAditiva                                  {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
;

expMultiplicativa:        expUnaria
                        | expUnaria '*' expUnaria                                           {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | expUnaria '/' expUnaria                                           {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
                        | expUnaria '%' expUnaria                                           {if(!$<tipoNumerico>1 || !$<tipoNumerico>3) printf("Error: Tipo incompatible\n"); else $<tipoNumerico>$ = 1;}
;

expUnaria:                expSufijo
                        | MASMAS expUnaria
                        | MENOSMENOS expUnaria
                        | operUnario expConversion
                        | SIZEOF '(' nombreTipo ')'
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

nombreTipo:               CHAR
                        | INT
                        | DOUBLE
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