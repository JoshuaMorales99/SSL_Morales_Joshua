// Importamos las librerias necesarias
//======================================
#include <stdio.h>      
#include <string.h>     // strlen
#include <ctype.h>      // toupper y isdigit
#include <math.h>       // pow
#define LongitudMaxima 50

// Funciones
//======================================
int caracterHexadecimal(char caracter) {
    
    // isdigit: Comprueba sin el carácter es un dígito numerico (0-9)
    if (isdigit(caracter)) return caracter - '0';   // '0' en ASCCI es 48

// toupper: Toma un caracter y devuelve el mismo pero en mayuscula
return 10 + (toupper(caracter) - 'A');  // 'A' en ASCCI es 65
}

unsigned long ConversorDecimal(char *numeroAConvertir, int longitud, int base){

    unsigned long decimal = 0;
    int potencia = 0;   // Empieza en "0" y se incrementa a medida que pasamos de caracter a caracter

    switch (base){
    case 8:     // Octal

        for (int i = longitud - 1; i >= 0; i --){
            // Obtener el decimal a partir del valor del caracter en ASCCI
            int valorActual = numeroAConvertir[i] - '0';    // '0' en ASCCI es 48
            // pow: base ^ potencia
            unsigned long elevado = pow (base, potencia) * valorActual;    // numero * 8 ^ potencia

            decimal += elevado;   // Sumamos valores
            potencia ++;
        }

    break;
    
    case 16:    // Hexadecimal

        if (numeroAConvertir[1] == 'x' || numeroAConvertir[1] == 'X')
        {
            for (int i = longitud - 1; i >= 2; i --){     // Para ignorar el "0x - 0X" en la operacion
                // Obtener el decimal a partir del valor del caracter en ASCCI
                int valorActual = caracterHexadecimal (numeroAConvertir[i]);
                unsigned long elevado = pow (base, potencia) * valorActual;    // numero * 16 ^ potencia

                decimal += elevado;
                potencia ++;
            }
        }
        else {
            // Por si el numero ingresado es hexadecimal pero no comienza con el "0x - 0X".
            // Se puede quitar suponiendo que todos los hexadecimales entrantes comienzan con "0x - 0X".
            for (int i = longitud - 1; i >= 0; i --){
                int valorActual = caracterHexadecimal (numeroAConvertir[i]);
                unsigned long elevado = pow (base, potencia) * valorActual;    // numero * 16 ^ potencia

                decimal += elevado;
                potencia ++;
            }
        }

    break;

    default:
        printf ("Por el momento, no contamos con esa conversion");
        getch();
        exit(-1);
    break;
    }

return decimal;
}

// Funcion "Main"
//======================================
int main(){

    char numeroAConvertir[LongitudMaxima] = "017010";  // Numero para pasarlo a decimal
    int base = 8;  // 8 = Octal    16 = Hexadecimal

    // strlen: Saber la longitud de la cadena
    unsigned long decimal = ConversorDecimal(numeroAConvertir, strlen(numeroAConvertir), base);

    // Mostrar por pantalla el resultado
    printf("El numero %s en base %d es: %lu en decimal", numeroAConvertir, base, decimal);
    getch();

return 0;
}