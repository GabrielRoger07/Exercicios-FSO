#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int contaSinais = 0;
void trata_sinal(int s);

int main(void){
    signal(SIGUSR1, trata_sinal);
    signal(SIGUSR2, trata_sinal);
    while(1){
        pause();
    }
}

void trata_sinal(int s){
    if((s == SIGUSR1 || s == SIGUSR2) && contaSinais == 0){
        contaSinais++;
        pid_t p = fork();
        if(p == 0){
            exit(0);
        }
    }else if((s == SIGUSR1 || s == SIGUSR2) && contaSinais == 1){
        contaSinais++;
        wait(NULL);
    }else if((s == SIGUSR1 || s == SIGUSR2) && contaSinais == 2){
        exit(0);
    }
}