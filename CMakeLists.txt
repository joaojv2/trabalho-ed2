cmake_minimum_required(VERSION 3.14)
project(trabalho_impl C)

set(CMAKE_C_STANDARD 99)

add_executable(trabalho_impl main.c selecao/selecao_substituicao.c selecao/selecao_substituicao.h selecao/selecao_natural.c selecao/selecao_natural.h intercalacao/arvore_vencedores.c intercalacao/arvore_vencedores.h estruturas/cliente.c estruturas/cliente.h estruturas/objeto.c estruturas/objeto.h arquivo/arquivo.c arquivo/arquivo.h)