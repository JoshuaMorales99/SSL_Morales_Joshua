%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>

    int yylex();
    int yyerror (char *);
    int yywrap(){
        return(1);
    }

%}

%union{
    int ival;
    char cval;
    char * cadena;
}

%token <ival> CONSTANTE CONSTANTE_OCTAL CONSTANTE_DECIMAL CONSTANTE_HEXADECIMAL CONSTANTE_REAL 
%token <cval> CONSTANTE_CARACTER

%type <ival> num
%type <cval> caracter

%start constantes

%%

constantes:   num
            | caracter
;

num:          CONSTANTE                     {printf("Constante\n");}
            | CONSTANTE_OCTAL               {printf("Octal\n");}
            | CONSTANTE_DECIMAL             {printf("Decimal\n");}
            | CONSTANTE_HEXADECIMAL         {printf("Hexadecimal\n");}
            | CONSTANTE_REAL                {printf("Real\n");}
;

caracter:     CONSTANTE_CARACTER            {printf("Caracter\n");}
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