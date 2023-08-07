#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int x = 0;

void trata_sinal(int s){
    printf("Recebi %d\n", s);
    if(s == SIGINT){
        x=1;
    }else if(x == 1 && s == SIGUSR2){
        x++;
    }else if(x == 2 && s == SIGTERM){
        printf("Senha acionada\n");
        x++;
    }else if(x == 3 && s == SIGUSR1){
        printf("Tchau\n");
        exit(0);
    }else{
        x=0;
    }
}

int main(void){
    signal(SIGTERM, trata_sinal);
    signal(SIGUSR1, trata_sinal);
    signal(SIGUSR2, trata_sinal);
    signal(SIGINT, trata_sinal);
    while(1){
        pause();
    }
}