#include <stdio.h>
#include <stdlib.h>

void heapSort(int *, int);
void criaHeap(int *, int, int);
void mostrar(int *, int);

int main (){

    int n, i;

    scanf("%d", &n);
    int *v = (int *) malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    mostrar(v, n);
    heapSort(v, n);
    mostrar(v, n);

    scanf("%d", &n);

    free(v);

    return 0;
}

void heapSort(int *v, int n){

    int i, aux;
    for(i=(n-1)/2; i>=0; i--){
        criaHeap(v, i, n-1);
    }
    for(i=n-1; i>=1; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i-1);
    }

}

void criaHeap(int *v, int i, int f){

    int aux, j, max=0;
    aux = v[i];
    j = (2*i)+1;
    while(j <= f){

        if(j<f){
            if(v[j] < v[j+1]){
                j++;
            }
        }
        if(aux < v[j]){
            v[i] = v[j];
            if(i==0 || j==0){
                max++;
            }
            i = j;
            j = (2*i)+1;
        }else{
            j = f+1;
        }
    }
    v[i] = aux;
    if(max != 0 || i == 0){
        mostrar(v, f+1);
    }
}

void mostrar(int *v, int n){
    int i;

    for(i=0; i<n; i++){
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}