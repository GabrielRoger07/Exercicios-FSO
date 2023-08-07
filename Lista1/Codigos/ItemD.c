#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int contaAlarme = 0;

void trata_sinal(int s);

int main(void){
    signal(SIGUSR1, trata_sinal);
    signal(SIGALRM, trata_sinal);
    while(1){
        pause();
    }
}

void trata_sinal(int s){
    if(s == SIGUSR1){
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }else{
        if(s == SIGALRM && contaAlarme<2){
            printf("Ai que sono, quero dormir mais um pouco\n");
            contaAlarme++;
        }else if(s == SIGALRM && contaAlarme==2){
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        }
    }
}

