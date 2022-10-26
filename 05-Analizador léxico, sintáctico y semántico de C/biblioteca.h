#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* =====================    N O D O S   ===================== */
typedef struct nodoTablaDeSimbolos{
    char * identificador;
    char * tipoDato;
    char estructura;  // F= funcion, V= variable, 
    int cantidadDeParametros;
    struct nodoParametros * parametros; 
    struct nodoTablaDeSimbolos * sig;  
}detalleTablaDeSimbolos;

typedef struct nodoParametros{ 
    char * identificador;
    char * tipoDato;
    struct nodoParametros * sig;
}detalleParametros;

typedef struct nodoSentenciasEncontradas{ // Crear el Nodo para elementos con tipo (Reservados y comentarios)
    char * tipoSentencia;
    int nroLinea;
    struct nodoSentenciasEncontradas * sig;
}detalleSentencia;


/* =====================    F U N C I O N E S   D E   L I S T A S  ===================== */
int buscarVariable(detalleTablaDeSimbolos * TablaDeSimbolos, char * identificador){
    detalleTablaDeSimbolos * aux = NULL;

    // Comprobamos si esta en Tabla de Simbolos
    for(aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
        // strcmp: Para comprobar si dos identificadores son iguales
        if (strcmp (aux -> identificador, identificador) == 0 && aux -> estructura == 'V') {
            return 1; // Esta en Tabla
        }
    }
    return 0; // No esta en Tabla
}


/* =====================    S E N T E N C I A S ===================== */
detalleSentencia* agregarListaSentencias (detalleSentencia *ListaSentencias, char *tipoSentencia, int nroLinea){
    
    /*Armo nuevo nodo con los datos ingresados por parámetro*/
    detalleSentencia *nuevoNodo = NULL;
    nuevoNodo = (detalleSentencia *) malloc(sizeof (detalleSentencia)); //Reservo memoria para el nodo
    nuevoNodo -> tipoSentencia = strdup (tipoSentencia);
    nuevoNodo -> nroLinea = nroLinea;
    nuevoNodo -> sig = NULL;

    /* Meto el nodo en la ListaSentencias de forma ordenada por nroLinea */
    detalleSentencia *aux = ListaSentencias;

    /* Para insertar el elemento en la primera posicion de la lista */
    if (aux == NULL || nroLinea < aux -> nroLinea){
        nuevoNodo -> sig = ListaSentencias;
        ListaSentencias = nuevoNodo;
    } else {
        // Para agregar el elementos en la posicion adecuada
        while (aux -> sig != NULL && aux -> sig -> nroLinea < nroLinea) aux = aux -> sig;
        if (aux -> sig != NULL) nuevoNodo -> sig = aux -> sig;
        aux -> sig = nuevoNodo;
    }

    return ListaSentencias;
}



int recorrerListaSentencias(detalleSentencia *ListaSentencias){

    if(ListaSentencias==NULL){

        printf("\n No se han encontrado sentencias.\n");

        return 1;
    }else{
        printf("\nSENTENCIAS\n\n");

        while(ListaSentencias!=NULL){
            printf("Linea %i: %s\n",ListaSentencias->nroLinea,ListaSentencias->tipoSentencia);
            ListaSentencias = ListaSentencias->sig;
        }

    }

    return 0;
}

/* =====================    C H E Q U E O S    ===================== */
int verificarParametrosYCambiar(detalleParametros * ListaAntParametros, detalleParametros *ListaDefParametros){
    detalleParametros * aux = NULL;
    detalleParametros * aux2 = NULL;
    for(aux = ListaAntParametros, aux2 = ListaDefParametros; aux != NULL && aux2 != NULL; aux = aux -> sig, aux2 = aux2 -> sig) {
        if (strcmp (aux -> tipoDato, aux2 -> tipoDato) == 0 ) {
            continue;
        } else {
            return 1;
        }
    }
    aux = NULL;
    aux2 = NULL;
    for(aux = ListaAntParametros, aux2 = ListaDefParametros; aux != NULL && aux2 != NULL; aux = aux -> sig, aux2 = aux2 -> sig) {
        aux-> identificador = aux2 -> identificador;
    }
    return 0;
}

int verificarFuncion (detalleTablaDeSimbolos *nuevoNodo, detalleTablaDeSimbolos * TablaDeSimbolos){
    detalleTablaDeSimbolos * aux = NULL;
    for(aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
        // strcmp: Para comprobar si dos identificadores son iguales
        if (strcmp (aux -> identificador, nuevoNodo -> identificador) == 0 && aux -> estructura == 'F') {
            // Para comprobar si los tipos de funciones son iguales
            if (strcmp (aux -> tipoDato, nuevoNodo -> tipoDato) == 0) {
                // Para comprobar que tengan la misma cantidad de parametros
                if(aux -> cantidadDeParametros == nuevoNodo -> cantidadDeParametros){
                    // Para comprobar que tengan los mismos tipos de parametros
                    if (verificarParametrosYCambiar(aux -> parametros, nuevoNodo -> parametros) == 0){

                        return 2;
                    } else {
                        printf("Error semantico: Validacion de tipos en parametros en funcion %s\n", aux -> identificador);
                        return 1;
                    }
                } else {
                    printf("Error semantico: Cantidad de parametros incorrecta en funcion %s\n", aux -> identificador);
                    return 1;
                }
            } else {
                printf("Error semantico: Validacion de tipos en funcion %s\n", aux -> identificador);
                return 1;
            }
        }
    }
    return 0;
}

/* =====================    T A B L A S   D E   S I M B O L O S    ===================== */

detalleTablaDeSimbolos* agregarAListaDeSimbolos (detalleTablaDeSimbolos * TablaDeSimbolos, char * identificador, char * tipoDato, char estructura, detalleParametros * ListaParametros, int cantidadDeParametros){
    detalleTablaDeSimbolos * aux = NULL;

    if(estructura == 'V'){ // variables
        // Comprobamos si hay doble declaración
        for(aux = TablaDeSimbolos; aux != NULL; aux = aux -> sig) {
            // strcmp: Para comprobar si dos Strings son iguales
            if (strcmp (aux -> identificador, identificador) == 0 && aux -> estructura == 'V') {
                printf("Error semantico: Doble declaracion del identificador %s\n", identificador);
                return TablaDeSimbolos; // Hubo coincidencia
            }
        }
    }
    
    /* Armo nuevo nodo con los datos ingresados por parámetro*/
    detalleTablaDeSimbolos *nuevoNodo = NULL;
    nuevoNodo = (detalleTablaDeSimbolos *) malloc(sizeof (detalleTablaDeSimbolos)); //Reservo memoria para el nodo
    nuevoNodo -> tipoDato = strdup (tipoDato);
    nuevoNodo -> identificador = strdup (identificador);
    nuevoNodo -> estructura = estructura;
    nuevoNodo -> cantidadDeParametros = cantidadDeParametros;
    nuevoNodo -> parametros = ListaParametros;
    nuevoNodo -> sig = NULL;

    if (estructura == 'F') { // funciones
        /*Meto el nodo en la ListaFunciones*/
        if(verificarFuncion (nuevoNodo, TablaDeSimbolos)!=0){
            return TablaDeSimbolos;
        } 
    }

    /* Meto el nodo en la TablaDeSimbolos */
    aux = TablaDeSimbolos;

    if (aux == NULL){
        TablaDeSimbolos = nuevoNodo;
    } else {
        /*Agrega las declaraciones reconocidas al final de la lista*/
        while (aux -> sig != NULL) aux = aux -> sig;
        if (aux -> sig == NULL) aux -> sig = nuevoNodo;
    }
    
    return TablaDeSimbolos;
}

int recorrerTablaDeSimbolos(detalleTablaDeSimbolos * TablaDeSimbolos){
    if(TablaDeSimbolos == NULL){
        printf("\n No se han encontrado datos en la tabla de simbolos.\n");
        return 1;
    }else{
        printf("\nTABLA DE SIMBOLOS\n\n");
        while(TablaDeSimbolos != NULL){

            if (TablaDeSimbolos -> estructura == 'F') {
                printf("Se encontro la funcion:\n--Identificador: %s,\n--De tipo: %s,\n--Cantidad de parametros: %d,\n",TablaDeSimbolos->identificador,TablaDeSimbolos->tipoDato,TablaDeSimbolos->cantidadDeParametros);
                while(TablaDeSimbolos -> parametros != NULL){
                    printf("----Parametro: %s %s,\n",TablaDeSimbolos->parametros->tipoDato, TablaDeSimbolos->parametros->identificador);
                    TablaDeSimbolos->parametros = TablaDeSimbolos->parametros->sig;
                }
                printf("\n");
            }

            if (TablaDeSimbolos->estructura == 'V') {
                printf("Se encontro la declaracion:\n--Identificador: %s,\n--De tipo: %s\n\n",TablaDeSimbolos->identificador,TablaDeSimbolos->tipoDato);
            }

            TablaDeSimbolos = TablaDeSimbolos->sig;
        }
    }

    return 0;
}

/* =====================    P A R A M E T R O S ===================== */
detalleParametros* agregarListaParametros (detalleParametros *ListaParametros, char *identificador, char *tipoDato){
    /*Armo nuevo nodo con los datos ingresados por parámetro*/
    detalleParametros *nuevoNodo = NULL;
    nuevoNodo = (detalleParametros *) malloc(sizeof (detalleParametros)); //Reservo memoria para el nodo
    nuevoNodo -> tipoDato = strdup (tipoDato);
    nuevoNodo -> identificador = strdup (identificador);
    nuevoNodo -> sig = NULL;

    /*Meto el nodo en la ListaParametros*/

    detalleParametros *aux = ListaParametros;
    if (aux == NULL){
        ListaParametros = nuevoNodo;
    } else {
        /*Agrega los parametros reconocidos al final de la lista*/
        while (aux -> sig != NULL) aux = aux -> sig;

        if (aux -> sig == NULL) aux -> sig = nuevoNodo;
    }
    
    return ListaParametros;
}