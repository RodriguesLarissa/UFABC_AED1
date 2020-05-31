#include <stdio.h>
#include <stdlib.h>

void adicionaMinHeap(int *, int, int);
void removeMinHeap(int *, int, int);
void criaHeap(int *, int, int);

int main (){

    int n, i, j, valor, op, cont=0;

    scanf("%d", &n);
    int *v = (int *) malloc(sizeof(int)*n);
    for(i=0; i<n; i++){

        scanf("%d", &op);

        if(op == 2 || op == 1){
            scanf("%d", &valor);
        }

        if(op == 1){
            cont++;
            adicionaMinHeap(v, cont, valor);
        }
        else if(op == 2){
            if(cont>0){
                removeMinHeap(v, cont, valor);
                cont--;
            }

        }
        else{
            if(cont > 0){
                printf("%d\n", v[0]);
            }
        }
    }

    free(v);
    return 0;
}

void adicionaMinHeap(int *v, int n, int valor){

    int i;
    v[n-1] = valor;
    for(i=(n-1)/2; i>=0; i--){
        criaHeap(v, i, n-1);
    }

}

void removeMinHeap(int *v, int n, int valor){

    int i, achei=0, aux, e, d, menor=0;
    for(i=0;  i<n && !achei; i++){
        if(v[i] == valor){
            achei = 1;
        }
    }
    i--;
    e=((2*i)+1), d=(e+1);
    while(e<=n-1 || d<=n-1){
        if(d<=n-1 && e<=n-1 && v[d]<= v[e]){
            menor = d;
        }
        else if(d<=n-1 && e<=n-1 && v[d] >= v[e]){
            menor = e;
        }
        else if(d<=n-1) {
            menor = d;
        }
        else if(e<=n-1){
            menor = e;
        }
        else{
            menor = i;
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        i = menor;
        e=((2*i)+1), d=(e+1);
    }
    menor = i;
    v[menor] = 0;
    if(i<n-1){
        for(; i<n-1; i++){
            v[i] = v[i+1];
        }
        v[i] = 0;
    }
    n--;
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