#include <stdio.h>
#include <stdlib.h>

void trataArquivos(int argc, char **argv){
    int k;
    int v; 
    int ret;
    for(k = 1; k < argc; k++){
        FILE *file1 = fopen(argv[k], "r");
        for(v = k+1; v < argc; v++){
            fseek(file1, 0, SEEK_SET);
            FILE *file2 = fopen(argv[v], "r");
            ret = arquivosIdenticos(file1, file2);
            if(ret == 1)
                printf("%s %s iguais\n", argv[k], argv[v]);
            else
                printf("%s %s diferentes\n", argv[k], argv[v]);
            fclose(file2);
        }
    fclose(file1);
    }
}

int arquivosIdenticos(FILE * ptr1, FILE * ptr2){
    int aux1, aux2;
    do{
        aux1 = fgetc(ptr1);
        aux2 = fgetc(ptr2);
        if (aux1 != aux2)
            return 0;

    } while (aux1 != EOF && aux2 != EOF);
    if (aux1 == EOF && aux2 == EOF)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv){
    trataArquivos(argc, argv);
    return 0;
}