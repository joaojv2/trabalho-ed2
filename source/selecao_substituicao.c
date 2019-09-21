//
// Created by joaovicttors on 27/08/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/arquivo.h"
#include "../header/utils.h"
#include "../header/objeto.h"
#include "../header/selecao_substituicao.h"

#define ONE 1

#define TRUE 1
#define FALSE 0

#define CONGELADO 1
#define DESCONGELADO 0

/**
 *
 *  @param arquivo
 *  @param size
 *  @return
 */
int selecao_substituicao(FILE *arquivo, int size) {

    int possivel_ler = TRUE, numero_particoes = ONE;
    int menor_codigo_cliente, menor_index_cliente;

    char diretorio_final[50] = {""};

    FILE *particao;

    Objeto *objeto_atual = (Objeto *) malloc(sizeof(Objeto));
    Objeto **simulacao_memoria = (Objeto **) malloc(sizeof(Objeto *) * size);

    preencher_objetos(arquivo, simulacao_memoria, size);

    while (possivel_ler == TRUE) {

        criar_diretorio_particao(numero_particoes, diretorio_final);
        particao = criar_arquivo_escrita(diretorio_final);

        descongelar_objetos(simulacao_memoria, size);

        while (object_descongelado(simulacao_memoria, size) == TRUE) {

            obter_menor_objeto(simulacao_memoria, objeto_atual, size);
            menor_index_cliente = objeto_atual->index;
            menor_codigo_cliente = objeto_atual->cliente->codigo;

            inserir_cliente_arquivo(particao, objeto_atual->cliente);

            if (possivel_ler == TRUE) {

                possivel_ler = procurar_client_arquivo(arquivo, simulacao_memoria[menor_index_cliente]->cliente);

                if (simulacao_memoria[menor_index_cliente]->cliente->codigo < menor_codigo_cliente) {
                    simulacao_memoria[menor_index_cliente]->congelado = CONGELADO;
                }
            } else {

                simulacao_memoria[menor_index_cliente]->cliente = NULL;
                simulacao_memoria[menor_index_cliente] = NULL;
            }
        }

        fclose(particao);
        printar_arquivo(diretorio_final);

        numero_particoes ++;
        limpar_diretorio_final(diretorio_final);
    }

    if (objeto_nao_nulo(simulacao_memoria, size) == TRUE) {

        criar_diretorio_particao(numero_particoes, diretorio_final);
        particao = criar_arquivo_escrita(diretorio_final);

        descongelar_objetos(simulacao_memoria, size);

        while (objeto_nao_nulo(simulacao_memoria, size) == TRUE) {

            obter_menor_objeto(simulacao_memoria, objeto_atual, size);
            menor_index_cliente = objeto_atual->index;

            inserir_cliente_arquivo(particao, objeto_atual->cliente);

            simulacao_memoria[menor_index_cliente]->cliente = NULL;
            simulacao_memoria[menor_index_cliente] = NULL;
        }

        fclose(particao);
        printar_arquivo(diretorio_final);

        limpar_diretorio_final(diretorio_final);
    }

    free(objeto_atual);
    free(simulacao_memoria);

    return numero_particoes - 1;
}