#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void procura_semente(int maisBaixo, int maisAlto, int tamanho){
    int auxiliar, final, auxiliarAleatorio;
    for(int i = maisBaixo; i <= maisAlto; i++){
        auxiliarAleatorio = i;
        auxiliar = 0;
        for(int j = 1; j < 100000; j++){
            rand_r(&auxiliarAleatorio);
        }
        final = (rand_r(&auxiliarAleatorio) % 8);
        if(final == tamanho){
            printf("%d\n", i);
        } 
        auxiliar++;
    }
}

int main(void){
    int maisBaixo, maisAlto, tamanho;
    scanf("%d %d %d", &maisBaixo, &maisAlto, &tamanho);
    procura_semente(maisBaixo, maisAlto, tamanho);
    return 0;
}