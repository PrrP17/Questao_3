//
// Created by morpheus on 04/10/2021.
//

#ifndef QUESTAO_3_LISTADINAMICA_H
#define QUESTAO_3_LISTADINAMICA_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct produto{
    int codido;
    char nome[30];
    float preco;
    int qtd;
};

typedef struct no* Lista;



Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_lista_inicio(Lista *li, struct produto pd);
int inserir_lista_final(Lista* li, struct produto pd);
int inserir_lista_ordenada(Lista *li, struct produto pd);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);

int busca_lista_cod(Lista* li, int cod, struct produto *pd);
void menor_preco(Lista* li);
void imprimir_lista(Lista* li);
int listas_concatenadas(Lista* l1, Lista* l2);
int remover_n_produtos(Lista* li, int num);
#endif //QUESTAO_3_LISTADINAMICA_H
