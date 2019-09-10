//
// Created by joaovicttors on 27/08/2019.
//

#ifndef TRABALHO_IMPL_OBJETO_H
#define TRABALHO_IMPL_OBJETO_H

#include "cliente.h"

typedef struct Objeto {

    int index;
    int congelado;
    Cliente *cliente;
} Objeto;

int objeto_nao_nulo(Objeto **objetos, int size);
int object_descongelado(Objeto **, int);

void descongela_objetos(Objeto **, int);
void preenche_objetos(FILE *, Objeto **, int);

Objeto *menor_objeto(Objeto **, int);

#endif //TRABALHO_IMPL_OBJETO_H
