#include "doublyLinkedList.h"

lista* inicializa_lista(){
    lista *novo_valor;
    novo_valor = (lista*) malloc(sizeof(lista));
    novo_valor->tamanho = 0;
    novo_valor->anterior = NULL;
    novo_valor->proximo = NULL;
    return novo_valor;
}

tarefa* inicializa_tarefa(int compt, int period){
    tarefa *task;
    task = (tarefa*)  malloc(sizeof(tarefa));
    task->periodo = period;
    task->computacao = compt;
    task->posicao = 0;
    task->prox = NULL;
    task->ant = NULL;
    return task;
}

void adiciona_na_lista(lista *list, tarefa *task){
    lista *novo_valor;
    if(list->proximo == NULL){
        list->proximo = task;
        list->anterior = task;
    }else{  
        novo_valor = (lista*) malloc(sizeof(lista));
        novo_valor->proximo = task;
        novo_valor->anterior = list->proximo;
        list->proximo = task;
        list->proximo->ant = novo_valor->anterior;
        novo_valor->anterior->prox = list->proximo;
        list->proximo->prox = NULL;
        free(novo_valor);
    }
    list->tamanho++;
    task->posicao = list->tamanho;
}

void printa_lista(lista *list){
    tarefa *task_iterator;
    if(list != NULL)
        task_iterator = list->anterior;
    else 
        task_iterator = NULL;
    if(task_iterator != NULL){
        while(task_iterator != NULL){
            printf("Computacao: %d; Periodo: %d; Posicao: %d\n",task_iterator->computacao, task_iterator->periodo, task_iterator->posicao);
            task_iterator = task_iterator->prox; 
        }
    }else
        printf("A lista esta vazia!");
}

void printa_lista_reversa(lista *list){
    tarefa *task_iterator;
    if(list != NULL)
        task_iterator = list->proximo;
    else 
        task_iterator = NULL;
    if(task_iterator != NULL){
        while(task_iterator != NULL){
            printf("Computacao: %d; Periodo: %d; Posicao: %d\n",task_iterator->computacao, task_iterator->periodo, task_iterator->posicao);
            task_iterator = task_iterator->ant; 
        }
    }else
        printf("A lista esta vazia!");
}

lista* apaga_lista(lista *list){
    tarefa *task_iterator;
    while(list->anterior != NULL){
        task_iterator = list->anterior;
        list->anterior = list->anterior->prox;
        free(task_iterator);
        task_iterator = NULL;
        list->tamanho--;
    }
    free(list);
    return NULL;
}

void recupera_extremidades(lista *list, tarefa *task){
    tarefa *task_aux = task;

    while(task_aux != NULL){
        list->anterior = task_aux;
        task_aux = task_aux->ant;
    }   

    while(task != NULL){
        list->proximo = task;
        task = task->prox;
    }    
}

tarefa* procura_na_lista(lista *list, int pos){
    tarefa *task_iterator;
    if(list != NULL)
        task_iterator = list->anterior;
    else 
        task_iterator = NULL;
    if(task_iterator != NULL){
        while(task_iterator != NULL){
            if(task_iterator->posicao == pos)
                break;
            else
                task_iterator = task_iterator->prox; 
        }
    }else
        printf("A lista esta vazia!");

    return task_iterator;
}