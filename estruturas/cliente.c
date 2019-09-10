//
// Created by joaovicttors on 27/08/2019.
//

#include <stdio.h>

#include "cliente.h"

#define ONE 1
#define ZERO 0

#define TRUE 1
#define FALSE 0

/**
 *  Le um cliente de um arquivo especifico.
 *
 *  @param file arquivo onde vai ser lido o cliente.
 *  @param cliente ponteiro do cliente onde deve ser escrito na leitura.
 *  @return retorna se conseguiu ler, 1 se conseguiu e 0 se deu erro.
 */
int find_cliente(FILE *file, Cliente *cliente) {

    if (fread(cliente, sizeof(Cliente), ONE, file)) {
        return TRUE;
    }

    return FALSE;
}

/**
 *  Insere um cliente em um arquivo especifico.
 *
 *  @param file arquivo para inserir o cliente.
 *  @param cliente cliente para ser inserido no arquivo.
 *  @return retorna se conseguiu escrever, 1 se conseguiu e 0 se deu erro.
 */
int insert_cliente(FILE *file, Cliente *cliente) {

    if (fwrite(cliente, sizeof(Cliente), ONE, file)) {
        return TRUE;
    }

    return FALSE;
}