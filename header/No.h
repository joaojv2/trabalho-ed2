//
// Created by joaovicttors on 9/21/19.
//

#ifndef TRABALHO_IMPL_NO_H
#define TRABALHO_IMPL_NO_H

#include <bits/types/FILE.h>
#include "cliente.h"

typedef struct No {

    FILE *particao;
    Cliente *cliente;
    struct No *vencedor;
    struct No *perdedor;

} No;

#endif //TRABALHO_IMPL_NO_H
