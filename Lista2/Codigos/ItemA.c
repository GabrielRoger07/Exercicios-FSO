#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int v1[10000000], v2[10000000];

struct thread_st{
    int *v; 
    int tam;
    pthread_t tid;
};

int compara(const void *a, const void *b){
    if(*(int *)a > *(int*)b) return 1;
    if(*(int *)a < *(int*)b) return -1;
    return 0;
}

void *ordena(void *t){
    struct thread_st *a = (struct thread_st*)t;
    qsort(a->v, a->tam, sizeof(int), compara);
}

void le_vetores(int verificador, int tamanho){
    if(verificador == 1){
        for(int i = 0; i < tamanho; i++){
            scanf("%d", &v1[i]);
        }
    }else{
        for(int i = 0; i < tamanho; i++){
            scanf("%d", &v2[i]);
        }
    }
}

int main(void){
    int tamanhoVetor, igual = 1;

    scanf("%d", &tamanhoVetor);

    le_vetores(1, tamanhoVetor);
    le_vetores(2, tamanhoVetor);

    struct thread_st t1, t2;
    t1.v = v1;
    t1.tam = tamanhoVetor;
    t2.v = v2;
    t2.tam = tamanhoVetor;

    pthread_create(&t1.tid, NULL, ordena, (void*)&t1);
    pthread_create(&t2.tid, NULL, ordena, (void*)&t2);

    pthread_join(t1.tid, NULL);
    pthread_join(t2.tid, NULL);

    for(int i = 0; i < tamanhoVetor; i++){
        if(!(v1[i] == v2[i])){
            igual = 0;
        }
    }

    if(igual == 1){
        printf("Mesmos elementos\n");
    }else{
        printf("Diferentes\n");
    }
    return 0;
}


