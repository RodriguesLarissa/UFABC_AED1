#include <stdio.h>
#include <stdlib.h>

void ordenaBubble(int *, int);
void leituraVetor(int *, int);

int main(){

    int i, tam;

    scanf("%d", &tam);

    int *vetor = (int *) malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        scanf("%d", &vetor[i]);
    }

    ordenaBubble(vetor, tam);

    free(vetor);

    return 0;
}

void ordenaBubble(int *v, int tam){

    int i, cont=0, aux, j, k;

    leituraVetor(v, tam);

    for(j=1; j<tam; j++){
        for(k=0; k<tam-1; k++){
            if(v[k] > v[k+1]){
                aux = v[k+1];
                v[k+1] = v[k];
                v[k] = aux;
                leituraVetor(v, tam);
                cont++;
            }
        }
    }

    leituraVetor(v, tam);

    printf("Trocas: %d\n", cont);

}

void leituraVetor(int *v, int tam){

    int i;

    for(i=0; i<tam; i++){
        printf("%d%s", v[i], i==tam-1?"\n":" ");
    }
}