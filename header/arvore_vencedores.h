//
// Created by joaovicttors on 27/08/2019.
//

#ifndef TRABALHO_IMPL_ARVORE_VENCEDORES_H
#define TRABALHO_IMPL_ARVORE_VENCEDORES_H

#include "cliente.h"
#include "No.h"

No **montar_arvore(int, No **);

void verificar_menor(int, int, No **, int *);

void arvore_binaria_vencedores(int );

No *inserir_novo_elemento_arvore(No *);

void criar_nos_folha_inicial(No **, FILE **, int);

#endif //TRABALHO_IMPL_ARVORE_VENCEDORES_H
