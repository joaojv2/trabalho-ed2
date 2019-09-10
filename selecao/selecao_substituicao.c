//
// Created by joaovicttors on 27/08/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "selecao_substituicao.h"
#include "../estruturas/objeto.h"
#include "../arquivo/arquivo.h"

#define ONE 1
#define ZERO 0

#define TRUE 1
#define FALSE 0

#define CONGELADO 1
#define DESCONGELADO 0

/**
 *
 *  @param file
 *  @param size
 *  @return
 */
char **selecao_substituicao(FILE *file, int size) {

    int possivel_ler = TRUE, particoes = ONE;
    int menor_codigo_cliente, menor_index_cliente;

//    char **diretorios;

    char extensao[50] = {".dat"};
    char caminho[50] = {"../particoes/particao"};
    char numero_particao[50] = {""};

    char diretorio[50] = {""};

    FILE *particao;

    Objeto *objeto_atual = NULL;

    Objeto **simulacao_memoria = (Objeto **) malloc(sizeof(Objeto *) * size);
    preenche_objetos(file, simulacao_memoria, size);

    while (possivel_ler == TRUE) {

        sprintf(numero_particao, "%d", particoes);

        strcat(diretorio, caminho);
        strcat(diretorio, numero_particao);
        strcat(diretorio, extensao);

        particao = cria_arquivo_escrita(diretorio);

        descongela_objetos(simulacao_memoria, size);

        while (object_descongelado(simulacao_memoria, size) == TRUE) {

            objeto_atual = menor_objeto(simulacao_memoria, size);
            menor_index_cliente = objeto_atual->index;
            menor_codigo_cliente = objeto_atual->cliente->codigo;

            insert_cliente(particao, objeto_atual->cliente);

            if (possivel_ler == TRUE) {

                possivel_ler = find_cliente(file, simulacao_memoria[menor_index_cliente]->cliente);

                if (simulacao_memoria[menor_index_cliente]->cliente->codigo < menor_codigo_cliente) {
                    simulacao_memoria[menor_index_cliente]->congelado = CONGELADO;
                }
            } else {

                simulacao_memoria[menor_index_cliente]->cliente = NULL;
                simulacao_memoria[menor_index_cliente] = NULL;
            }
        }

        fclose(particao);

        particoes ++;
        strcpy(diretorio, "");
    }

    if (objeto_nao_nulo(simulacao_memoria, size) == TRUE) {

        sprintf(numero_particao, "%d", particoes);

        strcat(diretorio, caminho);
        strcat(diretorio, numero_particao);
        strcat(diretorio, extensao);

        particao = cria_arquivo_escrita(diretorio);

        descongela_objetos(simulacao_memoria, size);

        while (objeto_nao_nulo(simulacao_memoria, size) == TRUE) {

            objeto_atual = menor_objeto(simulacao_memoria, size);
            menor_index_cliente = objeto_atual->index;

            insert_cliente(particao, objeto_atual->cliente);

            simulacao_memoria[menor_index_cliente]->cliente = NULL;
            simulacao_memoria[menor_index_cliente] = NULL;
        }

        fclose(particao);
        strcpy(diretorio, "");
    }

    free(simulacao_memoria);
}