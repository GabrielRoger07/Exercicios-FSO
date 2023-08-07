#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int sinalFilho1 = 0, sinalFilho2 = 0;
int m1[2000][2000], m2[2000][2000], m3[2000][2000];

void sinalF1(int s){
    sinalFilho1++;
}

void sinalF2(int s){
    sinalFilho2++;
}

void multiplica(int n, int l, int r, int s){
    for(int i = l; i < r; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    kill(getppid(), s);
    pause();

    for(int i = l; i < r; i++){
        printf("%d", m3[i][0]);
        for(int j = 1; j < n; j++){
            printf("%d", m3[i][j]);
        }
        printf("\n");
    }

    kill(getppid(), s);
    exit(0);
}

int main(void){

    int dimensao, metade, resto, sinal[2], s, l, r;
    pid_t filho[2];
    signal(SIGUSR1, sinalF1);
    signal(SIGUSR2, sinalF2);

    scanf("%d", &dimensao);
    metade = dimensao/2;
    resto = dimensao%2;
    sinal[0] = SIGUSR1;
    sinal[1] = SIGUSR2;

    for(int i = 0; i < dimensao; i++){
        for(int j = 0; j < dimensao; j++){
            scanf("%d", &m1[i][j]);
            m3[i][j] = 0;
        }
    }

    for(int i = 0; i < dimensao; i++){
        for(int j = 0; j < dimensao; j++){
            scanf("%d", &m2[i][j]);
        }
    }

    for(int i = 0; i < 2; i++){
        l = i*metade;
        s = sinal[i];
        if(i == 1){
            r = resto + i*metade + metade;
        }else{
            r = i*metade + metade;
        }
        filho[i] = fork();
        if(filho[i] == 0){
            multiplica(dimensao, l, r, sinal[i]);
        }
    }
    pause();
    while(sinalFilho1 == 0 || sinalFilho2 == 0){
        pause();
    }

    kill(filho[0], SIGUSR1);
    wait(NULL);
    kill(filho[1], SIGUSR1);
    wait(NULL);

}