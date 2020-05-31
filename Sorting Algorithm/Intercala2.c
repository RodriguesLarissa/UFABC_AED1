#include <stdio.h>
#include <stdlib.h>

void intercala(int *, int, int, int);

int main (){

    int n1, n2, i, n;

    scanf("%d %d", &n1, &n2);

    n = (n1+n2);

    int *v = (int *) malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    intercala(v, n, n1, n2);

    return 0;
}

void intercala(int *v1, int n, int n1, int n2){

    int i, j, k;
    int *v2 = (int *) malloc(sizeof(int)*n);

    for(i=0, j=0, k=n1; (i<n && j<n1 && k<n); i++){
        if(v1[j] < v1[k]){
            v2[i] = v1[j];
            j++;
        }
        else{
            v2[i] = v1[k];
            k++;
        }
    }

    if(j == n1 || n1 == 0){
        for(;k<n; k++, i++){
            v2[i] = v1[k];
        }
    }
    else if(k == n || n2 == 0){
        for(;j<n1; j++, i++){
            v2[i] = v1[j];
        }
    }

    for(i=0; i<n; i++){
        printf("%d\n", v2[i]);
    }

}