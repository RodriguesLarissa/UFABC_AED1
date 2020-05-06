#include <stdio.h>
#include <stdlib.h>

void ordena(int *, int, int);
int notaCorte(int *, int, int);

int main (){

    int cand, vagas, i;

    scanf("%d %d", &cand, &vagas);

    int *notas = (int *) malloc(sizeof(int)*cand);

    for(i=0; i<cand; i++){
        scanf("%d", &notas[i]);
    }

    ordena(notas, 0, cand-1);

    printf("%d\n", notaCorte(notas, cand, vagas));

    return 0;
}

void ordena(int *v, int inicio, int final){

    int pivo, meio = (inicio+final)/2, i=inicio, j=final, aux;
    pivo = v[meio];

    while(j >= i){
        while(v[i] < pivo){
            i++;
        }
        while(v[j] > pivo){
            j--;
        }
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if(inicio < j){
        ordena(v, inicio, j);
    }
    if(i<final){
        ordena(v, i, final);
    }

}

int notaCorte(int* notas, int tam, int vagas){

    int i, cont=vagas;
    int soma=0;

    for(i=tam-1; cont>0; cont--, i--){
        soma+=notas[i];
    }

    return soma/vagas;

}