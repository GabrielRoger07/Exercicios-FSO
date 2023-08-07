#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int quantPaginas, paginas[10001], quantQuadros, paginaMax = -1, quadroMax = 0, receba = 0, detectado = 0, pageFaults, val, inicial;

    scanf("%d", &quantPaginas);
    for (int i = 0; i < quantPaginas; i++)
        scanf("%d", &paginas[i]);

    while(scanf("%d", &quantQuadros) != EOF){
        pageFaults = 0;
        val = 0;
        inicial = 0;
        int *aux = malloc(quantQuadros*sizeof(int));
        for(int i = 0; i < quantPaginas; i++){
            if((val+1)%quantQuadros != inicial){
                if(val != inicial &&  busca(inicial, val, quantQuadros, aux, paginas[i]))
                    continue;
                else{
                    aux[val++] = paginas[i];
                    val = val == quantQuadros ? 0 : val;
                    pageFaults++;
                }
            }else{
                if(!busca(inicial, val, quantQuadros, aux, paginas[i])){
                    inicial++;
                    inicial = inicial == quantQuadros ? 0 : inicial;
                    aux[val++] = paginas[i];
                    val = val == quantQuadros ? 0 : val;
                    pageFaults++;
                }
            }
        }
        printf("%d %d\n", quantQuadros, pageFaults);
        if(receba == 0){
            receba = 1;
            paginaMax = pageFaults;
            quadroMax = quantQuadros;
        }else if(pageFaults > paginaMax && quantQuadros > quadroMax){
            paginaMax = pageFaults;
            quadroMax = quantQuadros;
            detectado = 1;
        }
    }
    if(detectado){
        printf("Belady detectado\n");
    }else {
        printf("Sem anomalia\n");
    }
    return 0;
}

int busca(int r, int l, int quantQuadros, int *aux, int pagina){
    for (int i = r; ; i = (i+1)%quantQuadros){
        if(aux[i] == pagina)
            return 1;
        if(i == l)
            break;
    }
    return 0;
}