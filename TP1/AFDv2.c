#include <stdio.h>

/*                                V A R I A B L E S       G L O B A L E S
=========================================================================================================== */
char caracter0 = '0';                                                                       // Caracter 0
int B = 7;
char caracteres1_7[] = {'1','2','3','4','5','6','7'};                                       // Caracteres [1 - 7]
int C = 2;
char caracteres8_9[] = {'8','9'};                                                           // Caracteres [8, 9]
int D = 2;
char caracteresx_X[] = {'x','X'};                                                           // Caracteres [x, X]
int E = 12;
char caracteresa_F[] = {'a','b','c','d','e','f','A','B','C','D','E','F'};                   // Caracteres [a - f, A - F]



/*                      F U N C I O N E S:      E S T A D O S      D E L      A F D
=========================================================================================================== */
char q0(char caracter){                                                                     // ESTADO INICIAL (q0)

    char TipoCadena;                                                                        // VARIABLE: d = "Decimal", O = "Octal", n = "No Reconocido"
    if (caracter == caracter0)                                                              // Saber si la cadena puede ser un "Octal"
    {
        return TipoCadena = 'O';
    }

    for (int i = 0; i < B; i++)                                                             // Saber si la cadena puede ser un "Decimal"
    {
        if (caracter == caracteres1_7[i])
        {
            return TipoCadena = 'd';
        }
    }
    for (int j = 0; j < C; j++)                                                             // Saber si la cadena puede ser un "Decimal"
    {
        if (caracter == caracteres8_9[j])
        {
            return TipoCadena = 'd';
        }
    }

return TipoCadena = 'n';                                                                    // La cadena es un "No Reconocido"
}


char q1(FILE* fleer, char caracter){                                                        // ESTADO FINAL (q1)

    char TipoCadena;                                                                        // VARIABLE: o = "Octal", H = "Hexadecimal/No Reconocido", n = "No Reconocido"
    if (caracter == caracter0)                                                              // Saber si la cadena sigue siendo de tipo "Octal"
    {
        return TipoCadena = 'o';
    }
    for (int i = 0; i < B; i++)                                                             // Saber si la cadena sigue siendo de tipo "Octal"
    {
        if (caracter == caracteres1_7[i])
        {
            return TipoCadena = 'o';
        }
    }

    for (int j = 0; j < D; j++)                                                             // Saber si la cadena puede ser de tipo "Hexadecimal"
    {
        if (caracter == caracteresx_X[j])
        {
            return TipoCadena = 'H';
        }
    }
    
return TipoCadena = 'n';                                                                    // La cadena es un "No Reconocido"
}


char q2(FILE* fleer, char caracter){                                                        // ESTADO FINAL (q2)

    char TipoCadena;                                                                        // VARIABLE: d = "Decimal", n = "No Reconocida"
    if (caracter == caracter0)                                                              // Saber si la cadena sigue siendo de tipo "Decimal"
    {   
        return TipoCadena = 'd';
    }
    for (int i = 0; i < B; i++)                                                             // Saber si la cadena sigue siendo de tipo "Decimal"
    {
        if (caracter == caracteres1_7[i])
        {
            return TipoCadena = 'd';
        }
    }
    for (int j = 0; j < C; j++)                                                             // Saber si la cadena sigue siendo de tipo "Decimal"
    {
        if (caracter == caracteres8_9[j])
        {
            return TipoCadena = 'd';
        }
    }
    
return TipoCadena = 'n';                                                                    // La cadena es un "No Reconocido"
}


char q3_q4(FILE* fleer, char caracter){                                                     // ESTADO NO FINAL (q3) y ESTADO FINAL (q4)

    char TipoCadena;                                                                        // VARIABLE: h = "Hexadecimal", n = "No Reconocida"
    if (caracter == caracter0)                                                              // Saber si la cadena sigue siendo de tipo "Hexadecimal"
    {
        return TipoCadena = 'h';
    }
    for (int i = 0; i < B; i++)                                                             // Saber si la cadena sigue siendo de tipo "Hexadecimal"
    {
        if (caracter == caracteres1_7[i])
        {
            return TipoCadena = 'h';
        }
    }
    for (int j = 0; j < C; j++)                                                             // Saber si la cadena sigue siendo de tipo "Hexadecimal"
    {
        if (caracter == caracteres8_9[j])
        {
            return TipoCadena = 'h';
        }
    }
    for (int k = 0; k < E; k++)                                                             // Saber si la cadena sigue siendo de tipo "Hexadecimal"
    {
        if (caracter == caracteresa_F[k])
        {
            return TipoCadena = 'h';
        }
    }
    
return TipoCadena = 'n';                                                                    // La cadena es un "No Reconocido"
}


char q5(FILE* fleer, char caracter){                                                        // ESTADO FINAL (q5)

    char TipoCadena;                                                                        // VARIABLE: o = "Octal", n = "No Reconocida"
    if (caracter == caracter0)                                                              // Saber si la cadena sigue siendo de tipo "Octal"
    {
        return TipoCadena = 'o';
    }
    for (int i = 0; i < B; i++)                                                             // Saber si la cadena sigue siendo de tipo "Octal"
    {
        if (caracter == caracteres1_7[i])
        {
            return TipoCadena = 'o';
        }
    }
    
return TipoCadena = 'n';                                                                    // La cadena es un "No Reconocido"
}



/*                                              F U N C I O N E S
=========================================================================================================== */
void EscribirLenguaje(FILE* fleer, FILE* fescribir){                                        // Escribir el Lenguaje del fichero "fleer"

    char caracter;                                                                          // VARIABLE: Caracter de la cadena
    fprintf(fescribir, "El documento contiene el siguiente lenguaje:\n\n\tL = {");
    
    while ((caracter = fgetc(fleer)) != EOF)                                                // Escribir el Lenguaje entero
    {
        fprintf(fescribir, "%c", caracter);
    }

    fprintf(fescribir, "}\n\nLas cadenas del Lenguaje \"L\" son del siguiente Tipo:\n");
    rewind(fleer);                                                                          // Colocar el puntero en la posicion inicial del Lenguaje

return;
}


void LimpiarValiables(char TipoCadena, char caracter){                                      // Limpiar Variables para evitar errores

    TipoCadena = 'n';
    caracter = '\0';

return;
}


void EscribirResultados(FILE* fescribir, char TipoCadena){                                  // Escribir resultados

    if (TipoCadena == 'd')
    {
        fprintf(fescribir, "\t\t\t[Decimal]\n");
    }
    if (TipoCadena == 'O' || TipoCadena == 'o')
    {
        fprintf(fescribir, "\t\t\t[Octal]\n");
    }
    if (TipoCadena == 'h')
    {
        fprintf(fescribir, "\t\t\t[Hexadecimal]\n");
    }
    if (TipoCadena == 'n' || TipoCadena == 'H')
    {
        fprintf(fescribir, "\t\t\t[No Registrado]\n");
    }

return;
}


void RecorrerAutomata(FILE* fleer, FILE* fescribir){                                        // Recorrer Automata para clasificar las cadenas de caracteres

    char TipoCadena = 'n';                                                                  // VARIABLE: d = "Decimal", O,o = "Octal", H = "Hexadecimal/No Reconocido" h = "Hexadecimal", n = "No Reconocido"
    char caracter;

    while ((caracter = fgetc(fleer)) != EOF)                                                // BUCLE: Permite empezar a recorrer cada cadena del Lenguaje
    {   
        fprintf(fescribir, "\n\t- %c", caracter);                                           // Escrbir el primer caracter de la Cadena

        TipoCadena = q0(caracter);                                                          // ESTADO INICIAL del Automata: (q0)

        while ((caracter != ',') && (caracter != EOF))                                      // BUCLE: Permite clasificar la cadena leyendo de caracter a caracter
        {   
            caracter = fgetc(fleer);                                                        // Asignar a la Variable el valor del caracter siguiente de la cadena

            if (caracter == ',' || caracter == EOF)                                         // Omitir la "," y el "EOF" para evitar errores
            {
                break;
            }

            fprintf(fescribir, "%c", caracter);                                             // Escribir los siguientes caracteres de la Cadena

            switch (TipoCadena)                                                             // Clasificar la cadena de caracteres
            {
                case 'O':                                                                   // ESTADO FINAL del Automata: (q1)
                    TipoCadena = q1(fleer, caracter);
                break;

                case 'd':                                                                   // ESTADO FINAL del Automata: (q2)
                    TipoCadena = q2(fleer, caracter);
                break;

                case 'H':                                                                   // ESTADO NO FINAL del Automata: (q3)
                    TipoCadena = q3_q4(fleer, caracter);
                break;

                case 'h':
                    TipoCadena = q3_q4(fleer, caracter);                                    // ESTADO FINAL del Automata (q4)
                break;

                case 'o':                                                                   // ESTADO FINAL del Automata (q5)
                    TipoCadena = q5(fleer, caracter);
                break;

                default:
                break;
            }
        }

        LimpiarValiables(TipoCadena, caracter);                                             // Llamar a la funcion "LimpiarVariable"
        EscribirResultados(fescribir, TipoCadena);                                          // Llamar a la funcion "EscribirResultados"

    }

return;
}



/*                                                M A I N
=========================================================================================================== */
int main(){

    FILE* fleer = fopen("Entrada.txt", "r");                                                // Abrir fichero "fleer" en modo solo lectura (r)
    if (fleer == NULL)                                                                      // Comprobar que el fichero "fleer" se haya abierto bien
    {
        printf("\nError al abrir archivo \"Entrada.txt\"\n");
        return 0;
    }
    FILE* fescribir = fopen("Salida.txt", "w");                                             // Abrir fichero "fescribir" en modo solo escritura (w)
    if (fescribir == NULL)                                                                  // Comprobar que el fichero "fescribir" se haya abierto bien
    {
        printf("\nError al abrir archivo \"Salida.txt\"\n");
        return 0;
    }

    EscribirLenguaje(fleer, fescribir);                                                     // Llamar a la funcion "EscribirLenguaje"
    RecorrerAutomata(fleer, fescribir);                                                     // Llamar a la funcion "RecorrerAutomata"

    fclose(fleer);                                                                          // Cerrar fichero "fleer"
    fclose(fescribir);                                                                      // Cerrar fichero "fescribir"

    printf("Clasificacion completada con exito!!!");                                        // Mensaje de exitoso
    getch();

return 0;
}