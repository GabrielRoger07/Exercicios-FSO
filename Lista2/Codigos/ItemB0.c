#include <stdio.h>
#include <stdlib.h>

int valoresEncontrados[10000000];

int main(void){
    int maisBaixo, maisAlto, tamanho;
    scanf("%d %d", &maisBaixo, &maisAlto);
    tamanho = carrega_encontrados();
    printf("%d\n", procura_semente(maisBaixo, maisAlto, tamanho));
    return 0;
}

int carrega_encontrados(){
    int numero, total = 0;
    while(scanf("%d", &numero) != EOF){
        valoresEncontrados[total++] = numero;
    }
    return total;
}

int procura_semente(int maisBaixo, int maisAlto, int tamanho){
    int final, auxiliar1, auxiliarAleatorio;
    
    for(int i = maisBaixo; i <= maisAlto; i++){
        auxiliarAleatorio = i;
        auxiliar1 = 0;

        for(int j = 0; j < tamanho; j++){
            for(int k=1; k<10000; k++){
                rand_r(&auxiliarAleatorio);
            }
            final = (rand_r(&auxiliarAleatorio) % 256);
            if(final != valoresEncontrados[auxiliar1]){
                break;
            }
            if(auxiliar1 == tamanho-1 && final == valoresEncontrados[auxiliar1]){
                return i;
            } 
            auxiliar1++;
        }
    }
}