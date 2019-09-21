//
// Created by joaovicttors on 27/08/2019.
//

#include <bits/types/FILE.h>

#ifndef TRABALHO_IMPL_CLIENTE_H
#define TRABALHO_IMPL_CLIENTE_H

typedef struct Cliente {

    int codigo;
    char nome[50];
    char data_nascimento[20];

} Cliente;

int procurar_client_arquivo(FILE *, Cliente *);
int inserir_cliente_arquivo(FILE *, Cliente *);

#endif //TRABALHO_IMPL_CLIENTE_H
