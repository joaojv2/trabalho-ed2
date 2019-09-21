//
// Created by joaovicttors on 27/08/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "../header/objeto.h"

#define ONE 1

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
void descongelar_objetos(Objeto **objetos, int size) {

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
void obter_menor_objeto(Objeto **objetos, Objeto *menor_objeto, int size) {

    int menor = 999;

    for (int i = 0; i < size; i ++) {
        if (objetos[i] != NULL) {
            if (objetos[i]->congelado == DESCONGELADO && objetos[i]->cliente->codigo < menor) {
                *menor_objeto = *objetos[i];
                menor = menor_objeto->cliente->codigo;
            }
        }
    }
}

/**
 *
 *  @param arquivo
 *  @param objetos
 *  @param size
 */
void preencher_objetos(FILE *arquivo, Objeto **objetos, int size) {

    for (int i = 0; i < size; i ++) {

        objetos[i] = (Objeto *) malloc(sizeof(Objeto));

        objetos[i]->index = i;
        objetos[i]->congelado = DESCONGELADO;

        objetos[i]->cliente = (Cliente *) malloc(sizeof(Cliente));
        procurar_client_arquivo(arquivo, objetos[i]->cliente);
    }
}