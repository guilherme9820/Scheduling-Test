#include "quickSortPointer.h"

int dividir(lista *list, int esquerda, int direita){
	int cont = esquerda;
	int pos_aux;
	int i = esquerda + 1;
	tarefa *task_iterator, *aux_cont, *aux_iterator, *aux1, *aux2, *esquerda_aux;
	tarefa *iterator_prox, *cont_ant;
	esquerda_aux = procura_na_lista(list, esquerda);
	task_iterator = esquerda_aux->prox;

	if(task_iterator != NULL){
		while(i <= direita){
			if(esquerda_aux->periodo > task_iterator->periodo){
	            cont++;
	            pos_aux = task_iterator->posicao;
	            aux_iterator = task_iterator;
	            aux_cont = procura_na_lista(list, cont);
	            iterator_prox = task_iterator->prox;
	            cont_ant = aux_cont->ant;

	            if(aux_cont->prox == aux_iterator){
		            aux_iterator->ant = cont_ant;
		            aux_cont->prox = iterator_prox;
		            if(iterator_prox != NULL)
		           		iterator_prox->ant = aux_cont;
		            aux_iterator->prox = aux_cont;
		            if(cont_ant != NULL)
		            	cont_ant->prox = aux_iterator;
		            aux_cont->ant = aux_iterator;
	            }else{
	            	aux2 = aux_cont->prox;
	            	aux1 = aux_iterator->ant;
	            	if(aux2 != NULL)
		            	aux2->ant = aux_iterator;
		            aux_cont->prox = aux_iterator->prox;
		            if(iterator_prox != NULL)
		           		iterator_prox->ant = aux_cont;
		            aux_iterator->prox = aux2;
		            aux_iterator->ant = cont_ant;
		            if(cont_ant != NULL)
		            	cont_ant->prox = aux_iterator;
		            aux_cont->ant = aux1;
		            aux1->prox = aux_cont;
	        	}
        		task_iterator->posicao = aux_cont->posicao;
	            aux_cont->posicao = pos_aux;
	            task_iterator = aux_cont;
	        }
			task_iterator = task_iterator->prox; 
			i++;
		}
        if(cont != esquerda){
        	aux_cont = procura_na_lista(list, cont);
	        cont_ant = aux_cont->prox;
	        iterator_prox = esquerda_aux->ant;
	        pos_aux = aux_cont->posicao;
        	if(esquerda == cont-1){
	            aux_cont->ant = iterator_prox;
	            aux_cont->prox = esquerda_aux;
	            if(iterator_prox != NULL)
	           		iterator_prox->prox = aux_cont;
	            esquerda_aux->ant = aux_cont;
	            if(cont_ant != NULL)
	            	cont_ant->ant = esquerda_aux;
	            esquerda_aux->prox = cont_ant;        		
        	}else{
        		aux1 = aux_cont->ant;
	        	aux2 = esquerda_aux->prox;
		        aux2->ant = aux_cont;
		        esquerda_aux->prox = cont_ant;
		        if(cont_ant != NULL)
		        	cont_ant->ant = esquerda_aux;
		        aux_cont->prox = aux2;
		        aux_cont->ant = iterator_prox;
		        if(esquerda_aux->ant !=NULL)
		        	iterator_prox->prox = aux_cont;
		        esquerda_aux->ant = aux1;
		        aux1->prox = esquerda_aux;
        	}
			aux_cont->posicao = esquerda_aux->posicao;
	        esquerda_aux->posicao = pos_aux;
	        
	        recupera_extremidades(list, aux_cont);       
	    }
	}else
		printf("A lista esta vazia!\n");

    return cont;
}

void quickSort(lista *list, int esquerda, int direita){
	int pivo;

	if(esquerda < direita){
        pivo = dividir(list, esquerda, direita);
        quickSort(list, esquerda, pivo-1);
        quickSort(list, pivo+1, direita);
    }
}