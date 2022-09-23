%option noyywrap
%option yylineno

%{

    #include <stdio.h>
    #include <stdlib.h>
    #include "BNF.tab.h"

%}

CONSTANTE_DECIMAL               [1-9][0-9]*
CONSTANTE_OCTAL                 0[0-7]*
CONSTANTE_HEXADECIMAL           0[xX][0-9A-Fa-f]+
CONSTANTE_REAL                  [0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)?
CONSTANTE_CARACTER              '.'

%%

{CONSTANTE_OCTAL}               {return CONSTANTE_OCTAL;}
{CONSTANTE_DECIMAL}             {return CONSTANTE_DECIMAL;}
{CONSTANTE_HEXADECIMAL}         {return CONSTANTE_HEXADECIMAL;}
{CONSTANTE_REAL}                {return CONSTANTE_REAL;}
{CONSTANTE_CARACTER}            {return CONSTANTE_CARACTER;}

%%