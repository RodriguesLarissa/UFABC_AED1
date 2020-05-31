#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int, int, int);
int particiona(int *, int, int, int);
void mostrar(int *, int);

int main (){

    int i,n;

    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    mostrar(v, n);
    quickSort(v, 0, n-1, n);
    mostrar(v, n);

    free(v);
    return 0;
}

void quickSort(int *v, int inicio, int fim, int n){

    int pivo;
    if(fim > inicio){
        pivo = particiona(v, inicio, fim, n);
        quickSort(v, inicio, pivo-1, n);
        quickSort(v, pivo+1, fim, n);
    }

}

int particiona(int *v, int inicio, int fim, int n){

    int aux, i=inicio, j, pivo;

    pivo = v[fim];

    for(j=inicio; j<fim; j++){
        if(v[j] <= pivo){
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
            i++;
        }
        mostrar(v, n);
    }

    aux = v[i];
    v[i] = v[fim];
    v[fim] = aux;
    mostrar(v, n);
    return i;

}

void mostrar(int *v, int n){

    int i;

    for(i=0; i<n; i++){
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}