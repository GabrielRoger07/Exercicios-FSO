#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int valoresEncontrados[10000000];

struct st{
    int maisBaixo, maisAlto, tamanho, q;
};

int carrega_encontrados(){
    int numero, total = 0;
    while(scanf("%d", &numero) != EOF){
        valoresEncontrados[total++] = numero;
    }
    return total;
}

void *procura_semente(void *val){
    int auxiliar, final, auxiliarAleatorio;
    struct st *p = (struct st*)val;

    for(int i = p->maisBaixo; i <= p->maisAlto; i++){
        auxiliarAleatorio = i;
        auxiliar = 0;

        for(int j = 0; j < p->tamanho; j++){
            for(int k=1; k<10000; k++){
                rand_r(&auxiliarAleatorio);
            }

            final = (rand_r(&auxiliarAleatorio) % 256);

            if(final != valoresEncontrados[auxiliar]){
                break;
            }  

            if(auxiliar == p->tamanho-1 && final == valoresEncontrados[auxiliar]){
                printf("%d\n", i);
                return;
            } 
            auxiliar++;
        }
    }
}

int main(void){
    int maisBaixo, maisAlto, tamanho;
    scanf("%d %d", &maisBaixo, &maisAlto);
    tamanho = carrega_encontrados();

    struct st val1, val2;

    val1.maisBaixo = maisBaixo;
    val1.maisAlto = (maisBaixo + maisAlto)/2;
    val1.q = 0;
    val1.tamanho = tamanho;

    val2.maisBaixo = val1.maisAlto + 1;
    val2.maisAlto = maisAlto;
    val2.q = 1;
    val2.tamanho = tamanho;

    pthread_t t1, t2;

    pthread_create(&t1, NULL, procura_semente, (void *)&val1);
    pthread_create(&t2, NULL, procura_semente, (void *)&val2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}