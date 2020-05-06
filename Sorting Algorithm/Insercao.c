#include <stdio.h>
#include <stdlib.h>

void ordena(int *, int, int);
void mostra(int *, int);

int main (){

    int tam, i, n;

    scanf("%d", &tam);

    int *vetor = malloc(sizeof(int)*(tam-1));

    for(i=0; i<tam-1; i++){
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &n);

    ordena(vetor, tam, n);

    free(vetor);

    return 0;
}

void ordena(int *v, int tam, int n){

    int i, achei=0;

    for(i=tam-2; i>=0 && !achei; i--){
        if(v[i] > n){
            v[i+1] = v[i];
            mostra(v, tam);
        }
        else{
            v[i+1] = n;
            achei = 1;
            mostra(v, tam);
        }
    }
    if(i < 0 && v[0] > n){
        v[0] = n;
        mostra(v, tam);
    }

}

void mostra(int *v, int tam){

    int i;

    for(i=0; i<tam; i++){
        printf("%d%s", v[i], i==tam-1?"\n":" ");
    }
}