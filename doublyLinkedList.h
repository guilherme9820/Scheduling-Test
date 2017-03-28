#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__
#include <stdio.h>
#include <stdlib.h>

typedef struct proc{
    int periodo;
    int computacao;
    int posicao;
    struct proc *prox;
    struct proc *ant;
}tarefa;

typedef struct list{
    int tamanho;
    tarefa *anterior;
    tarefa *proximo;
}lista;

lista* inicializa_lista();

tarefa* inicializa_tarefa(int compt, int period);

void adiciona_na_lista(lista *list, tarefa *task);

void printa_lista(lista *list);

void printa_lista_reversa(lista *list);

lista* apaga_lista(lista *list);

void recupera_extremidades(lista *list, tarefa *task);

tarefa* procura_na_lista(lista *list, int pos);

#endif