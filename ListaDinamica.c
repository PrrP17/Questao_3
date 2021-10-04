//
// Created by Paulo Roberto on 03/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamica.h"

struct no{
    struct produto dados;
    struct no *prox;
};

typedef struct no No;

Lista* criar_lista(){
    Lista * li = (Lista*) malloc (sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void liberar_lista(Lista* li){
    if (li != NULL){
        No* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if (li == NULL)
        return 0;
    int cont = 0;
    No* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

int inserir_lista_inicio(Lista *li, struct produto pd){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = pd;
    novo_no->prox = (*li);
    *li = novo_no;
    return 1;
}

int inserir_lista_final(Lista *li, struct produto pd){
    if (li == NULL)
        return 0;
    No *novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = pd;
    novo_no->prox = NULL;
    if((*li) == NULL){
        *li = novo_no;
    } else {
        No *aux;
        aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo_no;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct produto pd){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = pd;
    if((*li) == NULL){
        novo_no->prox = NULL;
        *li = novo_no;
        return 1;
    } else{
        No *ant, *atual = *li;
        while (atual != NULL && atual->dados.codido < pd.codido){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            novo_no->prox = (*li);
            *li = novo_no;
        } else {
            novo_no->prox = atual;
            ant->prox = novo_no;
        }
        return 1;
    }
}

int remover_lista_inicio(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remover_lista_final(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remover_lista(Lista* li, int cod){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *ant, *no = *li;
    while(no != NULL && no->dados.codido != cod){
        ant = no;
        no = no->prox;
    }
    if (no == NULL)
        return 0;

    if (no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int busca_lista_cod(Lista* li, int cod, struct produto *pd){
    if (li == NULL)
        return 0;
    No *no = *li;
    while(no != NULL && no->dados.codido != cod)
        no = no->prox;
    if (no == NULL)
        return 0;
    else{
        *pd = no->dados;
        return 1;
    }
}

void menor_preco(Lista* li){
    No *no = *li;
    float menor = no->dados.preco;
    while(no != NULL){
        if(no->dados.preco < menor){
            menor = no->dados.preco;
        }
        no = no->prox;
    }
    printf("O menor preco é: %.2f", menor);


}

//ATV

int listas_concatenadas(Lista* l1, Lista* l2){
    if(l1 == NULL || l2 == NULL)
        return 0;
    if((*l1) == NULL)
        return 0;
    No *aux = *l1;
    while(aux != NULL){
        inserir_lista_final(l2, aux->dados);
        aux = aux->prox;
    }
    return 1;
}

int remover_n_produtos(Lista* li, int num){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    No *aux = *li;
    int i = 1;
    if(num < tamanho_lista(li)){
        while(aux != NULL && i <= num ){
            aux = aux->prox;
            *li = aux;
            free(aux);
            i++;
        }
        printf("\nOperacao realizada com sucesso!");
    }
    return 1;
}

int muda_pos(Lista* li, int pos1, int pos2){
    if(li == NULL || pos1 <= 0 || pos2 <= 0 || pos1 == pos2)
        return 0;
    No *no = *li;
    No *no2 = *li;
    No aux;
    int i = 1;
    int j = 1;
    while(no != NULL && i < pos1){
        no = no->prox;
        i++;
    }
    while(no2 != NULL && j < pos2){
        no2 = no2->prox;
        j++;
    }
    aux.dados = no->dados;
    no->dados = no2->dados;
    no2->dados = aux.dados;

    return 1;
}

void imprimir_lista(Lista* li){
    if (li == NULL)
        printf("Lista vazia\n");
    No* ler_no = (*li);
    printf("-------------\n");
    while(ler_no != NULL){
        printf("Matricula: %d\n", ler_no->dados.codido);
        printf("Nome: %s\n", ler_no->dados.nome);
        printf("Preco: %2.1f\n", ler_no->dados.preco);
        printf("qtd: %d\n", ler_no->dados.qtd);
        printf("-------------\n");
        ler_no = ler_no->prox;
    }
}
