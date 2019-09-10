//
// Created by joaovicttors on 28/08/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"

#define ERRO 0
#define SUCESSO 1

#define ONE 1
#define ZERO 0

#define ESCRITA "w+b"
#define LEITURA "a+b"

FILE *cria_arquivo_escrita(char *diretorio) {

    FILE *file;

    if ((file = fopen(diretorio, ESCRITA)) == NULL) {
        printf("Error opening file!\n");
        exit(ONE);
    }

    return file;
}

FILE *abre_arquivo_leitura(char *diretorio) {

    FILE *file;

    if ((file = fopen(diretorio, LEITURA)) == NULL) {
        printf("Error opening file!\n");
        exit(ONE);
    }

    return file;
}