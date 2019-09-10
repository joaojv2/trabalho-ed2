//
// Created by joaovicttors on 27/08/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "objeto.h"

#define ONE 1
#define ZERO 0

#define TRUE 1
#define FALSE 0

#define CONGELADO 1
#define DESCONGELADO 0

/**
 *
 *  @param objetos
 *  @param size
 *  @return
 */
int objeto_nao_nulo(Objeto **objetos, int size) {

    for (int i = 0; i < size; i ++) {
        if (objetos[i] != NULL) {
            return TRUE;
        }
    }

    return FALSE;
}

/**
 *
 *  @param objetos
 *  @param size
 *  @return
 */
int object_descongelado(Objeto **objetos, int size) {

    for (int i = 0; i < size; i ++) {
        if (objetos[i] != NULL) {
            if (objetos[i]->congelado == DESCONGELADO) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

/**
 *
 *  @param objetos
 *  @param size
 */
void descongela_objetos(Objeto **objetos, int size) {

    for (int i = 0; i < size; i ++) {
        if (objetos[i] != NULL) {
            objetos[i]->congelado = DESCONGELADO;
        }
    }
}

/**
 *
 *  @param objetos
 *  @param cliente
 *  @param size
 */
Objeto *menor_objeto(Objeto **objetos, int size) {

    Objeto *objeto;
    int menor = 999;

    for (int i = 0; i < size; i ++) {
        if (objetos[i] != NULL) {
            if (objetos[i]->congelado == DESCONGELADO && objetos[i]->cliente->codigo < menor) {
                objeto = objetos[i];
                menor = objeto->cliente->codigo;
            }
        }
    }

    return objeto;
}

/**
 *
 *  @param file
 *  @param objetos
 *  @param size
 */
void preenche_objetos(FILE *file, Objeto **objetos, int size) {

    for (int i = 0; i < size; i ++) {

        objetos[i] = (Objeto *) malloc(sizeof(Objeto));

        objetos[i]->index = i;
        objetos[i]->congelado = DESCONGELADO;

        objetos[i]->cliente = (Cliente *) malloc(sizeof(Cliente));
        fread(objetos[i]->cliente, sizeof(Cliente), ONE, file);
    }
}