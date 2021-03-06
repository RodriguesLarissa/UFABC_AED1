#include <stdio.h>
#include <stdlib.h>

void maxHeap(int *, int);
void criaHeap(int *, int, int);
void mostrar(int *, int);

int main (){

    int n, i;

    scanf("%d", &n);
    while(n!=0){

        int *v = (int *) malloc(sizeof(int)*n);

        for(i=0; i<n; i++){
            scanf("%d", &v[i]);
        }

        maxHeap(v, n);
        mostrar(v, n);

        scanf("%d", &n);

        free(v);
    }

    return 0;
}

void maxHeap(int *v, int n){

    int i, aux, cont=0;
    for(i=(n-1)/2; i>=0; i--){
        criaHeap(v, i, n-1);
    }
}

void criaHeap(int *v, int i, int f){

    int e=((2*i)+1), d=(e+1), menor=0, aux;
    if(e<=f && v[e]< v[i]){
        menor = e;
    }
    else{
        menor = i;
    }

    if(d<=f && v[d] <= v[menor]){
        menor = d;
    }

    if(menor != i){
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        criaHeap(v, menor, f);
    }
}

void mostrar(int *v, int n){
    int i;

    for(i=0; i<n; i++){
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}