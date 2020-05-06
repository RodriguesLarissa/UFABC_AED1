#include <stdio.h>
#include <stdlib.h>

void ordenaSelection(int *, int);
void mostraVetor(int *, int);

int main (){

    int tam, i;

    scanf("%d", &tam);

    int *vetor = (int *) malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        scanf("%d", &vetor[i]);
    }

    ordenaSelection(vetor, tam);

    free(vetor);

    return 0;
}

void ordenaSelection(int *v, int tam){

    int i, j, aux, cont=0, menor;

    mostraVetor(v, tam);

    for(i=0; i<tam-1;i++){
        menor = i;
        for(j=i+1; j<tam; j++){
            if(v[j] < v[menor]){
                menor = j;
                cont++;
            }
        }
        if(i != menor){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
        mostraVetor(v, tam);
    }

    mostraVetor(v, tam);

    printf("%d\n", cont);

}

void mostraVetor(int *v, int tam){

    int i;

    for(i=0; i<tam; i++){
        printf("%d%s", v[i], i==tam-1?"\n":" ");
    }
}