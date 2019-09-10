#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "selecao/selecao_substituicao.h"
#include "estruturas/cliente.h"
#include "arquivo/arquivo.h"

#define ONE 1
#define ZERO 0

#define MIN 1
#define MAX 300

#define ESCRITA "w+b"
#define LEITURA "a+b"

#define NOME_DEFAULT "test"
#define DATA_DEFAULT "01/01/01"

void gera_random_database(char *, int);
int gera_codigo_cliente(int, int);

int main() {

    int size = 6, size_database = 40000000;
    char diretorio[50] = {"../particoes/database.dat"};

    FILE *file;

    gera_random_database(diretorio, size_database);
    file = abre_arquivo_leitura(diretorio);

    selecao_substituicao(file, size);

    fclose(file);

    return 0;
}

/**
 *
 *  @param diretorio
 *  @param size
 */
void gera_random_database(char *diretorio, int size) {

    FILE *file;
    Cliente *cliente;

    if ((file = fopen(diretorio, ESCRITA)) == NULL) {

        printf("Error opening your file!\n");
        exit(ONE);
    }

    cliente = (Cliente *) malloc(sizeof(Cliente));

    for (int i = 0; i < size; i ++) {

        cliente->codigo = gera_codigo_cliente(MIN, MAX);
        strcpy(cliente->nome, NOME_DEFAULT);
        strcpy(cliente->data_nascimento, DATA_DEFAULT);

        insert_cliente(file, cliente);
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
int gera_codigo_cliente(int numero_minimo, int numero_maximo) {

    return rand() % ((numero_maximo + 1) - numero_minimo) + numero_minimo;
}