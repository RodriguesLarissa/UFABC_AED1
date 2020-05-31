#include <stdio.h>
#include <stdlib.h>

void intercala(int *, int *, int, int);

int main (){

    int i, n1, n2;

    scanf("%d %d", &n1, &n2);

    int *v1 = (int *) malloc(sizeof(int)*n1);
    int *v2 = (int *) malloc(sizeof(int)*n2);

    for(i=0; i<n1; i++){
        scanf("%d", &v1[i]);
    }

    for(i=0; i<n2; i++){
        scanf("%d", &v2[i]);
    }

    intercala(v1, v2, n1, n2);

    return 0;
}

void intercala(int *v1, int *v2, int n1, int n2){

    int i, j, k;
    int n = (n1+n2);
    int *v = (int *) malloc(sizeof(int)*(n));

    for(i=0, j=0, k=0; (i<n && j<n1 && k<n2); i++){
        if(v1[j] >= v2[k]){
            v[i] = v2[k];
            k++;
        }
        else{
            v[i] = v1[j];
            j++;
        }
    }

    if(j == n1 || n1 == 0){
        for(;k<n2; k++, i++){
            v[i] = v2[k];
        }
    }
    else if(k == n2 || n2 == 0){
        for(;j<n1; j++, i++){
            v[i] = v1[j];
        }
    }

    for(i=0; i<n; i++){
        printf("%d\n", v[i]);
    }
}