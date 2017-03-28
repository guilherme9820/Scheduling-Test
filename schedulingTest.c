#include "schedulingTest.h"

void testa_escalonamento(lista *list){
    int p, c, pos, j;
    bool flag;
    float r, interference, result;
    tarefa *task;
    int k;
    for(k = 2; k <= list->tamanho; k++){
        task = procura_na_lista(list, k);
        p = task->periodo;
        c = task->computacao;
        pos = task->posicao;
        r = 0;
        flag = false;
        while(r < p){
            interference = 0;
            j = 1;
            while(j <= (pos - 1)){
                task = procura_na_lista(list, j);
                interference = ceil((r/(float)task->periodo)*((float)task->computacao)) + interference;
                j++;
            }
            r = c + interference;
            if(r == result){
                flag = true;
                break;
            }
            result = r;
        }
    }

    if(!flag)
        printf("Os processos nao sao escalonaveis!\n");
    else
        printf("Os processos sao escalonaveis!\n");
}