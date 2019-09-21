//
// Created by joaovicttors on 27/08/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "../header/arvore_vencedores.h"
#include "../header/utils.h"
#include "../header/arquivo.h"

#define MAX 310

/*
 *  @param numero_particoes
 */
void arvore_binaria_vencedores(int numero_particoes) {

    FILE **arquivos_abertos = (FILE **) malloc(numero_particoes * sizeof(FILE));
    No **nos_folha = (No **) malloc(numero_particoes * sizeof(No));

    criar_nos_folha_inicial(nos_folha, arquivos_abertos, numero_particoes);

    // criar o arquivo que vai escrever o arquivo ordenado final
    char diretorio_arquivo_final[50] = {};
    criar_diretorio_arquivo_final(diretorio_arquivo_final);
    FILE *arquivo_final = criar_arquivo_escrita(diretorio_arquivo_final);

    No **arvore_montada = montar_arvore(numero_particoes, nos_folha);

    while (arvore_montada[0]->cliente->codigo != MAX) {
        inserir_cliente_arquivo(arquivo_final, arvore_montada[0]->cliente);
        inserir_novo_elemento_arvore(arvore_montada[0]);
    }

    printf("\nARQUIVO ORDENADO COM SUCESSO!\n\n");

    for (int i = 0; i < numero_particoes; i ++) {
        fclose(arquivos_abertos[i]);
    }

    fclose(arquivo_final);

    printar_arquivo(diretorio_arquivo_final);
}

/**
 *
 *  @param nos_folha
 *  @param arquivos_abertos
 *  @param numero_particoes
 */
void criar_nos_folha_inicial(No **nos_folha, FILE **arquivos_abertos, int numero_particoes) {

    for (int i = 1; i <= numero_particoes; i ++) {

        char particao_diretorio[50] = {};
        criar_diretorio_particao(i, particao_diretorio);

        arquivos_abertos[i - 1] = abrir_arquivo_leitura(particao_diretorio);

        nos_folha[i - 1] = (No *) malloc(sizeof(No));
        nos_folha[i - 1]->cliente = (Cliente *) malloc(sizeof(Cliente));

        procurar_client_arquivo(arquivos_abertos[i - 1], nos_folha[i - 1]->cliente);

        nos_folha[i - 1]->particao = arquivos_abertos[i - 1];
        nos_folha[i - 1]->vencedor = NULL;
        nos_folha[i - 1]->perdedor = NULL;
    }
}

/**
 *
 *  @param no_raiz
 *  @return
 */
No *inserir_novo_elemento_arvore(No *no_raiz) {

    if (no_raiz->vencedor == NULL) {
        if (procurar_client_arquivo(no_raiz->particao, no_raiz->cliente)) {
            return no_raiz;
        } else {
            no_raiz->cliente->codigo = MAX;
            return no_raiz;
        }
    }

    inserir_novo_elemento_arvore(no_raiz->vencedor);

    if (no_raiz->perdedor->cliente->codigo < no_raiz->vencedor->cliente->codigo) {
        No *no_auxiliar = no_raiz->vencedor;
        no_raiz->vencedor = no_raiz->perdedor;
        no_raiz->perdedor = no_auxiliar;
    }

    no_raiz->cliente = no_raiz->vencedor->cliente;
    return no_raiz;
}

/**
 *
 *  @param numero_particoes
 *  @param nos_folha
 *  @return
 */
No **montar_arvore(int numero_particoes, No **nos_folha) {

    int i, f;

    int numero_N = numero_particoes / 2;
    int resto_N = numero_particoes % 2;

    int *indices = (int *) malloc(2 * sizeof(int));

    No *no_raiz;

    No **novos_nos_folha = (No **) malloc((numero_N + resto_N) * sizeof(No));

    for (i = 0, f = 0; i < numero_N; i ++, f += 2) {

        no_raiz = (No *) malloc(sizeof(No));

        verificar_menor(f, f + 1, nos_folha, indices);

        no_raiz->cliente = nos_folha[indices[0]]->cliente;
        no_raiz->vencedor = nos_folha[indices[0]];
        no_raiz->perdedor = nos_folha[indices[1]]; /** ver isso aqui */

        novos_nos_folha[i] = no_raiz;
    }

    if (resto_N > 0) {

        for (; f < numero_particoes; f ++, i++) {
            novos_nos_folha[i] = nos_folha[f];
        }
    }

    free(indices);

    if (numero_N + resto_N != 1) {

        return montar_arvore((numero_N + resto_N), novos_nos_folha);
    }

    return novos_nos_folha;
}

/**
 *
 *  @param indice_no_esquerda
 *  @param indice_no_direita
 *  @param nos_folha
 *  @param indices
 */
void verificar_menor(int indice_no_esquerda, int indice_no_direita, No **nos_folha, int *indices) {

    if (nos_folha[indice_no_esquerda]->cliente->codigo <= nos_folha[indice_no_direita]->cliente->codigo) {
        indices[0] = indice_no_esquerda;
        indices[1] = indice_no_direita;
    } else {
        indices[0] = indice_no_direita;
        indices[1] = indice_no_esquerda;
    }
}