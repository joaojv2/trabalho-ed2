//
// Created by joaovicttors on 9/20/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/utils.h"
#include "../header/cliente.h"

#define ONE 1
#define ZERO 0

#define MIN 1
#define MAX 300

#define ESCRITA "w+b"
#define LEITURA "a+b"

#define NOME_DEFAULT "test"
#define DATA_DEFAULT "01/01/01"

#define EXTENSAO ".dat"
#define DIRETORIO "../particoes/particao"
#define DIRETORIO_FINAL "../particoes/resultado"

/**
 *
 * @param diretorio_final
 */
void limpar_diretorio_final(char *diretorio_final) {

    strcpy(diretorio_final, "");
}

/**
 *
 * @param numero_particao
 * @param diretorio_final
 */
void criar_diretorio_particao(int numero_particao, char *diretorio_final) {

    char numero_particao_char[10] = {};

    sprintf(numero_particao_char, "%d", numero_particao);

    strcat(diretorio_final, DIRETORIO);
    strcat(diretorio_final, numero_particao_char);
    strcat(diretorio_final, EXTENSAO);
}

/**
 *
 *  @param diretorio_final
 */
void criar_diretorio_arquivo_final(char *diretorio_final) {

    strcat(diretorio_final, DIRETORIO_FINAL);
    strcat(diretorio_final, EXTENSAO);
}

/**
 *
 *  @param diretorio
 *  @param size
 */
void gerar_random_database(char *diretorio, int size) {

    FILE *file;
    Cliente *cliente;

    if ((file = fopen(diretorio, ESCRITA)) == NULL) {

        printf("Error opening your file!\n");
        exit(ONE);
    }

    cliente = (Cliente *) malloc(sizeof(Cliente));

    for (int i = 0; i < size; i ++) {

        cliente->codigo = gerar_codigo_cliente(MIN, MAX);
        strcpy(cliente->nome, NOME_DEFAULT);
        strcpy(cliente->data_nascimento, DATA_DEFAULT);

        inserir_cliente_arquivo(file, cliente);
    }

    free(cliente);
    fclose(file);
}

/**
 *
 *  @param numero_minimo
 *  @param numero_maximo
 *  @return
 */
int gerar_codigo_cliente(int numero_minimo, int numero_maximo) {

    return rand() % ((numero_maximo + 1) - numero_minimo) + numero_minimo;
}
