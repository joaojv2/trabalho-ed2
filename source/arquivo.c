//
// Created by joaovicttors on 28/08/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "../header/arquivo.h"
#include "../header/cliente.h"

#define ONE 1

#define ESCRITA "w+b"
#define LEITURA "a+b"

/**
 *
 *  @param diretorio
 *  @return
 */
FILE *criar_arquivo_escrita(char *diretorio) {

    FILE *file;

    if ((file = fopen(diretorio, ESCRITA)) == NULL) {
        printf("Error opening file!\n");
        exit(ONE);
    }

    return file;
}

/**
 *
 *  @param diretorio
 *  @return
 */
FILE *abrir_arquivo_leitura(char *diretorio) {

    FILE *file;

    if ((file = fopen(diretorio, LEITURA)) == NULL) {
        printf("Error opening file!\n");
        exit(ONE);
    }

    return file;
}


/**
 *
 *  @param diretorio
 */
void printar_arquivo(char *diretorio) {

    FILE *arquivo = abrir_arquivo_leitura(diretorio);
    Cliente *cliente = (Cliente *) malloc(sizeof(Cliente));

    printf("DIRETORIO -> %s\n", diretorio);

    while (procurar_client_arquivo(arquivo, cliente) != 0) {
        printf("CODIGO DO CLIENT -> %i ", cliente->codigo);
    }

    printf("\n");

    fclose(arquivo);
    free(cliente);
}
