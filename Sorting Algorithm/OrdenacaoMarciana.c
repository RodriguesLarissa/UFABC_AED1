#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ordena(int *, int *, int, int);
int troca(int, int *);

int main (){

    int tam, i;

    scanf("%d", &tam);

    int *v = (int *) malloc(sizeof(int)*tam);
    int *ordem = (int *) malloc(sizeof(int)*10);

    for(i=0; i<tam; i++){
        scanf("%d", &v[i]);
    }

    ordem[0] = 0;
    ordem[5] = 1;
    ordem[6] = 2;
    ordem[4] = 3;
    ordem[8] = 4;
    ordem[9] = 5;
    ordem[7] = 6;
    ordem[3] = 7;
    ordem[1] = 8;
    ordem[2] = 9;

    ordena(v, ordem, 0, tam-1);

    for(i=0; i<tam; i++){
        printf("%d%s", v[i], i==tam-1?"\n":" ");
    }

    free(v);
    free(ordem);
    return 0;
}

void ordena(int *v, int *ordem, int inicio, int final){

    int pivo, meio = (inicio+final)/2, i=inicio, j=final, aux, v1, v2;
    pivo = troca(v[meio], ordem);

    while(j >= i){
        while(troca(v[i], ordem) < pivo){
            i++;
        }
        while(troca(v[j], ordem) > pivo){
            j--;
        }
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if(inicio < j){
        ordena(v, ordem, inicio, j);
    }
    if(i<final){
        ordena(v, ordem, i, final);
    }

}

int troca(int v, int *ordem){

    int i, aux, resultado=0,  cont =0;

    aux = v;

    while(aux!=0){
        aux/=10;
        cont++;
    }

    int *n = (int *) malloc(sizeof(int)*cont);

    if(v <= 9){
        return ordem[v];
    }
    else{
        n[0] = v%10;
        for(i=1; i<cont; i++){
            if(i!=cont-1){
                n[i] =(int) (v/pow(10, i))%10;
            }
            else{
                n[i] = v/pow(10, i);
            }
        }

        for(i=0;  i<cont; i++){
            n[i] = ordem[n[i]];
        }

        for(i=cont-1;  i>=0; i--){
            resultado += (n[i]*pow(10, i));
        }

        free(n);
        return resultado;
    }
}