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

%token <ival> CONSTANTE_OCTAL CONSTANTE_DECIMAL CONSTANTE_HEXADECIMAL CONSTANTE_REAL 
%token <cval> CONSTANTE_CARACTER

%type <ival> num

%start num

%%

num:      CONSTANTE_OCTAL               {printf("Octal");}
        |  CONSTANTE_DECIMAL            {printf("Decimal");}
        |  CONSTANTE_HEXADECIMAL        {printf("Hexadecimal");}
        |  CONSTANTE_REAL               {printf("Real");}
;

%%
int yyerror(char * mensaje){
    printf("Error: %s\n", mensaje);
}

int main(){

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif

    printf("Ingrese una constante entera: ");
    yyparse();

return 0;
}