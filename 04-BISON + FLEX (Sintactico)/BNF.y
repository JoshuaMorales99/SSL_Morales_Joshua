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
    char cval;
    char * cadena;
}

%token CONSTANTE_OCTAL CONSTANTE_DECIMAL CONSTANTE_HEXADECIMAL
%token CONSTANTE_REAL 
%token CONSTANTE_CARACTER

%start programaC

%%

programaC:                noC
                        | listaSentencias
                        | listaDeclaraciones
;

noC:                      COMENTARIO_UNA_LINEA
                        | COMENTARIO_VARIAS_LINEAS
;

expresion:                expAsignacion
;

expAsignacion:            expCondicional
                        | IDENTIFICADOR operAsignacion expAsignacion
;

operAsignacion:           '='
                        | ASIGNACIONSUMA
                        | ASIGNACIONMULTIPLICACION
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
                        | expRelacional IGUALDAD expIgualdad
                        | expRelacional DESIGUALDAD expIgualdad
;

expRelacional:            expAditiva
                        | expAditiva MAYORIGUAL expRelacional
                        | expAditiva MENORIGUAL expRelacional
                        | expAditiva '<' expRelacional
                        | expAditiva '>' expRelacional
;

expAditiva:               expMultiplicativa
                        | expMultiplicativa '+' expAditiva
                        | expMultiplicativa '-' expAditiva
;

expMultiplicativa:        expUnaria
                        | expUnaria '*' expMultiplicativa
                        | expUnaria '/' expMultiplicativa
                        | expUnaria '^' expMultiplicativa
                        | expUnaria '%' expMultiplicativa
;

expUnaria:                expSufijo
                        | INCREMENTO expUnaria
                        | DECREMENTO expUnaria
                        | operUnario expUnaria
                        | SIZEOF '(' tipoDato ')'
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
                        | expSufijo INCREMENTO
                        | expSufijo DECREMENTO
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
;

sentCompuesta:            '{' listaDeclaraciones listaSentencias '}'
                        | '{' listaDeclaraciones '}'
                        | '{' listaSentencias '}'
                        | '{' '}'
;

listaDeclaraciones:       declaracion
                        | declaracion listaDeclaraciones
;

declaracion:              tipoDato listaVariableSimple ';'
;

tipoDato:                 CHAR
                        | DOUBLE
                        | FLOAT
                        | INT
                        | LONG
                        | SHORT
;

listaVariableSimple:      unaVariable
                        | unaVariable ',' listaVariableSimple
;

unaVariable:              variable
                        | variable inicial
;

variable:               IDENTIFICADOR
;

inicial:                '=' constantes
;

listaSentencias:          sentencia
                        | sentencia listaSentencias
;

sentExpresion:            expresion ';'
                        | ';'
;

sentSeleccion:            IF '(' expresion ')' sentencia
                        | IF '(' expresion ')' sentencia ELSE sentencia
                        | SWITCH '(' expresion ')' sentSwitch
;

sentSwitch:               '{' sentCase sentDefault '}'
	                    | '{' sentCase '}'
	                    | '{' sentDefault '}'
	                    | '{' '}'
;

sentCase:                 CASE constante ':' sentencia
;

sentDefault:              DEFAULT ':' sentencia
;

sentIteracion:            WHILE '(' expresion ')' sentencia
                        | DO sentencia WHILE '(' expresion ')' ';'
                        | FOR '(' expresion ';' expresion ';' expresion ')' sentencia
                        | FOR '(' ';' expresion ';' expresion ')' sentencia
                        | FOR '(' expresion ';' ';' expresion ')' sentencia
                        | FOR '(' expresion ';' expresion ';' ')' sentencia
                        | FOR '(' ';' ';' expresion ')' sentencia
                        | FOR '(' expresion ';' ';' ')' sentencia
                        | FOR '(' ';' ';' ';' ')' sentencia
;

sentSalto:                BREAK ';'
                        | CONTINUE ';'
                        | RETURN expresion ';'
                        | RETURN ';'
                        | GOTO ';'
;

constante:                constanteEntera
                        | CONSTANTE_CARACTER            {printf("Caracter\n");}
                        | CONSTANTE_REAL                {printf("Real\n");}
;

constanteEntera:          CONSTANTE_OCTAL               {printf("Octal\n");}
                        | CONSTANTE_DECIMAL             {printf("Decimal\n");}
                        | CONSTANTE_HEXADECIMAL         {printf("Hexadecimal\n");}
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