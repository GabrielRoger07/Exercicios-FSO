#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <strings.h>

//SIGUSR1 - câmera do Igor3k
//SIGUSR2 - câmera do Monark
//SIGINT - câmera do Convidado 1
//SIGTERM - câmera do Convidado 2
//SIGALRM - câmera geral

void trata_sinal(int s);

int main(void){
    signal(SIGUSR1, trata_sinal);
    signal(SIGUSR2, trata_sinal);
    signal(SIGINT, trata_sinal);
    signal(SIGTERM, trata_sinal);
    signal(SIGALRM, trata_sinal);
    while(1){
        pause();
    }
}

void trata_sinal(int s){
    char str[20];
    if(scanf(" %[^\n]", str) != EOF){
        if(s == SIGUSR1 && strcmp(str, "Igor3k") == 0){
            printf("Certo\n");
        }else if(s == SIGUSR2 && strcmp(str, "Monark") == 0){
            printf("Certo\n");
        }else if(s == SIGINT && strcmp(str, "Con1") == 0){
            printf("Certo\n");
        }else if(s == SIGTERM && strcmp(str, "Con2") == 0){
            printf("Certo\n");
        }else if(s == SIGALRM && strcmp(str, "Silencio") == 0){
            printf("Certo\n");
        }else{
            printf("Erro\n");
        }
    }else{
        exit(0);
    }
}