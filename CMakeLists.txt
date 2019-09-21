cmake_minimum_required(VERSION 3.14)
project(trabalho_impl C)

set(CMAKE_C_STANDARD 99)

add_executable(trabalho_impl main.c source/selecao_substituicao.c header/selecao_substituicao.h source/arvore_vencedores.c header/arvore_vencedores.h source/cliente.c header/cliente.h source/objeto.c header/objeto.h source/arquivo.c header/arquivo.h source/utils.c header/utils.h source/No.c header/No.h)