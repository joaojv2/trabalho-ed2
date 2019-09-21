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

void descongelar_objetos(Objeto **, int);

void preencher_objetos(FILE *, Objeto **, int);

void obter_menor_objeto(Objeto **, Objeto *, int);

#endif //TRABALHO_IMPL_OBJETO_H
