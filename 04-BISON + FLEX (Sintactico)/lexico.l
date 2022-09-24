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
LITERAL_CADENA                  \".*\"
IDENTIFICADOR                   [_a-zA-Z][_a-zA-Z0-9]*
COMENTARIO_UNA_LINEA            \/\/.*
COMENTARIO_VARIAS_LINEAS        \/\*[^\*\/]*\*\/

%%

"{"		                        {return '{';};
"}"		                        {return '}';};
"="		                        {return '=';};
"<"		                        {return '<';};
">"		                        {return '>';};
"+"		                        {return '+';};
"-"		                        {return '-';};
"*"		                        {return '*';};
"/"		                        {return '/';};
"%"		                        {return '%';};
";"		                        {return ';';};
":"		                        {return ':';};
"("		                        {return '(';};
")"		                        {return ')';};
","		                        {return ',';};
"."                             {return '.';};
"?"                             {return '?';};
"!"                             {return '!';};
"["                             {return '[';};
"]"                             {return ']';};
"&"                             {return '&';};

"||"	                        {return OR;};
"&&"	                        {return AND;};
"=="	                        {return IGUALIGUAL;};
">="	                        {return MAYORIGUAL;};
"<="	                        {return MENORIGUAL;};
"!=" 	                        {return DIFERENTE;};
"+="                            {return MASIGUAL;};
"-="                            {return MENOSIGUAL;};
"*="                            {return PORIGUAL;};
"/="                            {return DIVISIONGUAL;};
"++"                            {return MASMAS;};
"--"                            {return MENOSMENOS;};
"->"                            {return FLECHA;};

auto                            {return AUTO;};
enum                            {return ENUM;};
register                        {return REGISTER;};
typedef                         {return TYPEDEF;};
extern                          {return EXTERN;};
sizeof                          {return SIZEOF;};
union                           {return UNION;};
goto                            {return GOTO;};
volatile                        {return VOLATILE;};

while 		                    {return WHILE;};
if		                        {return IF;};
else		                    {return ELSE;};
do		                        {return DO;};
switch		                    {return SWITCH;};
for		                        {return FOR;};
case		                    {return CASE;};
break		                    {return BREAK;};
default		                    {return DEFAULT;};
void                            {return VOID;};
continue                        {return CONTINUE;};
return                          {return RETURN;};

char		                    {return CHAR;};
double		                    {return DOUBLE;};
float		                    {return FLOAT;};
int		                        {return INT;};
long		                    {return LONG;};
short		                    {return SHORT;};
unsigned                        {return UNSIGNED;};
signed                          {return SIGNED;};
const                           {return CONST;};
static                          {return STATIC;};
struct                          {return STRUCT;};

{CONSTANTE_OCTAL}               {return CONSTANTE_OCTAL;};
{CONSTANTE_DECIMAL}             {return CONSTANTE_DECIMAL;};
{CONSTANTE_HEXADECIMAL}         {return CONSTANTE_HEXADECIMAL;};
{CONSTANTE_REAL}                {return CONSTANTE_REAL;};
{CONSTANTE_CARACTER}            {return CONSTANTE_CARACTER;};
{LITERAL_CADENA}                {return LITERAL_CADENA;};
{IDENTIFICADOR}                 {yylval.cadena=yytext; return IDENTIFICADOR;};
{COMENTARIO_UNA_LINEA}          {return COMENTARIO_UNA_LINEA;};
{COMENTARIO_VARIAS_LINEAS}      {return COMENTARIO_VARIAS_LINEAS;};

\n
\t
" "

%%