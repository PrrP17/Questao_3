#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinamica.h"

Lista * minha_lista;
struct produto pd;

int main() {
    minha_lista = criar_lista();
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

    imprimir_lista(minha_lista);

    menor_preco(minha_lista);

    liberar_lista(minha_lista);

    return 0;
}