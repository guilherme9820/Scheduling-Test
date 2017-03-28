#include <time.h>
#include "quickSortPointer.h"
#include "schedulingTest.h"
#define NUMERO_TAREFAS 3

int main(void) {
	
	lista *linked_list;
	tarefa *task;
	int i, c, p;

	linked_list = inicializa_lista();

	srand(time(NULL));


	for(i = 0; i < NUMERO_TAREFAS; i++){
		c = 1 + rand() % 50;
		p = c + rand() % 110;
		task = inicializa_tarefa(c, p);
		adiciona_na_lista(linked_list, task);
	}
	printa_lista(linked_list);
	printf("\n");
	quickSort(linked_list, 1, linked_list->tamanho);
	printa_lista(linked_list);
	printf("\n");
	
	testa_escalonamento(linked_list);
	return 0;
}
