#include <stdio.h>
#include <stdlib.h>

float mediana(float *, int);

int main (){

    int tam, i;

    scanf("%d", &tam);

    float *v = (float *) malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        scanf("%f", &v[i]);
    }

    printf("%.2f\n", mediana(v, tam));

    free(v);

    return 0;
}

float mediana(float *v, int tam){

    int i, j, aux;

    for(i=1; i<tam; i++){
        for(j=0; j<tam-1; j++){
            if(v[j] > v[j+1]){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }

    if(tam%2!=0){
        return v[tam/2];
    }
    else{
        return (v[tam/2]+v[(tam/2)-1])/2;
    }

}