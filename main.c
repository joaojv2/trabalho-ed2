#include <stdio.h>

#include "header/arquivo.h"
#include "header/utils.h"
#include "header/cliente.h"
#include "header/selecao_substituicao.h"
#include "header/arvore_vencedores.h"

#define ONE 1

#define MIN 1
#define MAX 300

#define ESCRITA "w+b"
#define LEITURA "a+b"

#define NOME_DEFAULT "test"
#define DATA_DEFAULT "01/01/01"


int main() {

    int size = 6, size_database = 100;
    char diretorio[50] = {"../particoes/database.dat"};

    FILE *file;

    gerar_random_database(diretorio, size_database);
    file = abrir_arquivo_leitura(diretorio);

    int numero_particoes = selecao_substituicao(file, size);

    printf("\nNUMERO FINAL DE PARTICOES -> %i\n", numero_particoes);

    fclose(file);

    arvore_binaria_vencedores(numero_particoes);

    return 0;
}