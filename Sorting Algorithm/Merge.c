#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int, int, int);
void mergeTwoArrays(int *, int, int, int, int);
void mostrar(int *, int);

int main (){

    int n, i;

    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    mostrar(v, n);
    mergeSort(v, 0, n-1, n);
    mostrar(v, n);

    return 0;
}

void mergeSort(int *v, int inicio, int fim, int n){

    int i;
    if(fim <= inicio){
        return;
    }
    int meio = inicio + (fim-inicio)/2;
    mergeSort(v, inicio, meio, n);
    mergeSort(v, meio+1, fim, n);
    mostrar(v, n);
    mergeTwoArrays(v, inicio, meio, fim, n);
}

void mergeTwoArrays(int *v, int inicio, int meio, int fim, int n){

    int k, i;
    int *temp = (int *) malloc(sizeof(int)*n);
    int indexOne = inicio;
    int indexTwo = meio+1;

    for(k=inicio; k<=fim; k++){
        temp[k] = v[k];
    }

    for(k=inicio; k<=fim; k++){
        if(indexOne > meio){
            v[k] = temp[indexTwo];
            indexTwo++;
        }
        else if(indexTwo > fim){
            v[k] = temp[indexOne];
            indexOne++;
        }
        else if(temp[indexOne] < temp[indexTwo]){
            v[k] =  temp[indexOne];
            indexOne++;
        }
        else{
            v[k] = temp[indexTwo];
            indexTwo++;
        }
    }
}

void mostrar(int *v, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}