#include <stdio.h>
#include <stdlib.h>

void particiona(int *, int, int);

int main (){

    int i, n, x;

    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    scanf("%d", &x);

    particiona(v, n, x);

    return 0;
}

void particiona(int *v, int n, int x){

    int i, cont=0;
    for(i=0; i<n; i++){
        if(v[i] < x){
            cont++;
        }
    }

    printf("%d\n", cont);

}