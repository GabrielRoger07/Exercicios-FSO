#include <stdlib.h>
#include <stdio.h>
#include  <pthread.h>
#include <semaphore.h>
#include <math.h>
sem_t sem1;
<<<<<<< HEAD
int valor1, valor2;

void *verificaQuasePrimo(void *num){
    int *numero = (int *)num, var = *numero++, ribas, numDivisores = 0;
    if(var <= 508079){
        return 508079;
    }
    if(var % 2 == 0){ // garantir que é ímpar, para encontrar o quase primo mais próximo mais fácil
        var++;
=======

int verificaQuasePrimo(int *num){
    int numero = *num++, ribas, numDivisores = 0;
    if(numero <= 508079){
        return 508079;
    }
    if(numero % 2 == 0){ // garantir que é ímpar, para encontrar o quase primo mais próximo mais fácil
        numero++;
>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
    }
    sem_wait(&sem1);
    while(numDivisores <= 10){
        int numDivisores = 0, i;
<<<<<<< HEAD
        ribas = sqrt(var);
        for(i = 3; i < ribas; i = i + 2){
            if(i < 11 && var % i == 0) break;
            if(i > 10 && var % i == 0) numDivisores++;
        }
        if(numDivisores >= 10) return (void *)var;
        var = var + 2;
=======
        ribas = sqrt(numero);
        for(i = 3; i < ribas; i = i + 2){
            if(i < 11 && numero % i == 0) break;
            if(i > 10 && numero % i == 0) numDivisores++;
        }
        if(numDivisores >= 10) return numero;
        numero = numero + 2;
>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
        numDivisores = 0;
    }
    sem_post(&sem1);
}

int main(void){
<<<<<<< HEAD
    void *retorno1, *retorno2;
=======
    int retorno1, retorno2;
    int valor1, valor2; 
>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
    pthread_t  thread1, thread2;
    // void *ret1, *ret2;
    int casosTeste, i;
    scanf("%d", &casosTeste);
    if(casosTeste % 2 != 0){
        for(i = casosTeste; casosTeste > 1; casosTeste = casosTeste - 2){
        scanf("%d %d", &valor1, &valor2);
        sem_init(&sem1, 0, 2);
<<<<<<< HEAD
        pthread_create(&thread1, NULL, verificaQuasePrimo, (void *)&valor1);
        pthread_create(&thread2, NULL, verificaQuasePrimo, (void *)&valor2);
        pthread_join(thread1, &retorno1);
        printf("%d\n", (int)retorno1);
        pthread_join(thread2, &retorno2);
        printf("%d\n", (int)retorno2);
=======
        pthread_create(&thread1, NULL, verificaQuasePrimo, &valor1);
        pthread_create(&thread2, NULL, verificaQuasePrimo, &valor2);
        pthread_join(thread1, &retorno1);
        printf("%d\n", retorno1);
        pthread_join(thread2, &retorno2);
        printf("%d\n", retorno2);
>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
        sem_destroy(&sem1);
        }   
        scanf("%d", &valor1);
        sem_init(&sem1, 0, 1);
<<<<<<< HEAD
        pthread_create(&thread1, NULL, verificaQuasePrimo, (void *)&valor1);
        pthread_join(thread1, &retorno1);
        printf("%d\n", (int)retorno1);
=======
        pthread_create(&thread1, NULL, verificaQuasePrimo, &valor1);
        pthread_join(thread1, &retorno1);
        printf("%d\n", retorno1);
>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
        sem_destroy(&sem1);
    }else{
        for(i = casosTeste; casosTeste > 0; casosTeste = casosTeste - 2){
        scanf("%d %d", &valor1, &valor2);
        sem_init(&sem1, 0, 2);
<<<<<<< HEAD
        pthread_create(&thread1, NULL, verificaQuasePrimo, (void *)&valor1);
        pthread_create(&thread2, NULL, verificaQuasePrimo, (void *)&valor2);
        pthread_join(thread1, &retorno1);
        printf("%d\n", (int)retorno1);
        pthread_join(thread2, &retorno2);
        printf("%d\n", (int)retorno2);
=======
        pthread_create(&thread1, NULL, verificaQuasePrimo, &valor1);
        pthread_create(&thread2, NULL, verificaQuasePrimo, &valor2);
        pthread_join(thread1, &retorno1);
        printf("%d\n", retorno1);
        pthread_join(thread2, &retorno2);
        printf("%d\n", retorno2);
>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
        sem_destroy(&sem1);
        }
    }
    return 0;
<<<<<<< HEAD
}
=======
}

>>>>>>> 5f32b1f5cf86cbe4d51b49db85ac1e77481d598f
