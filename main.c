#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinamica.h"

Lista *minha_lista, *minha_lista2, *minha_lista3;

struct produto pd;

int main(){
    minha_lista = criar_lista();
    minha_lista2 = criar_lista();
    minha_lista3 = criar_lista();
    printf("Lista criada\n");

    pd.codido = 1;
    strcpy(pd.nome, "notenook");
    pd.preco = 1456.25;
    pd.qtd = 100;
    inserir_lista_ordenada(minha_lista,pd);

    pd.codido = 2;
    strcpy(pd.nome, "fone");
    pd.preco = 356.25;
    pd.qtd = 500;
    inserir_lista_ordenada(minha_lista,pd);

    pd.codido = 3;
    strcpy(pd.nome, "tablet");
    pd.preco = 2000.00;
    pd.qtd = 75;
    inserir_lista_ordenada(minha_lista,pd);

    pd.codido = 4;
    strcpy(pd.nome, "smartphone");
    pd.preco = 2999.25;
    pd.qtd = 1000;
    inserir_lista_ordenada(minha_lista,pd);

    pd.codido = 5;
    strcpy(pd.nome, "TV");
    pd.preco = 5000.00;
    pd.qtd = 50;
    inserir_lista_ordenada(minha_lista,pd);

    //lista 2

    pd.codido = 11;
    strcpy(pd.nome, "camera");
    pd.preco = 2556.25;
    pd.qtd = 100;
    inserir_lista_ordenada(minha_lista2,pd);

    pd.codido = 12;
    strcpy(pd.nome, "Caixa de som");
    pd.preco = 1356.25;
    pd.qtd = 500;
    inserir_lista_ordenada(minha_lista2,pd);

    pd.codido = 13;
    strcpy(pd.nome, "Microfone");
    pd.preco = 200.00;
    pd.qtd = 75;
    inserir_lista_ordenada(minha_lista2,pd);

    pd.codido = 14;
    strcpy(pd.nome, "Iphone");
    pd.preco = 10000.00;
    pd.qtd = 1000;
    inserir_lista_ordenada(minha_lista2,pd);

    pd.codido = 15;
    strcpy(pd.nome, "Projetor");
    pd.preco = 2500.00;
    pd.qtd = 50;
    inserir_lista_ordenada(minha_lista2,pd);

   // imprimir_lista(minha_lista);
    //imprimir_lista(minha_lista2);

    listas_concatenadas(minha_lista,minha_lista2);
    listas_concatenadas(minha_lista2, minha_lista3);

    imprimir_lista(minha_lista3);
    menor_preco(minha_lista3);
    remover_n_produtos(minha_lista, 1);

    liberar_lista(minha_lista);
    liberar_lista(minha_lista2);
    liberar_lista(minha_lista3);

    return 0;
}