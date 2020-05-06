#include <stdio.h>
#include <stdlib.h>

int ordenado(int *, int);

int main (){

    int tam, i;

    while(scanf("%d", &tam) != EOF){
        int *v = (int *) malloc(sizeof(int)*tam);

        for(i=0; i<tam; i++){
            scanf("%d", &v[i]);
        }

        printf("%s\n", ordenado(v, tam)?"S":"N");
        free(v);
    }

    return 0;
}

int ordenado(int *v, int tam){

   int i, contCrescente=0, contDecrescente=0;

   if(tam == 0){
       return 1;
   }

   for(i=0; i<tam-1; i++){
       if(v[i] == v[i+1]){
           contCrescente++;
           contDecrescente++;
       }
       else if(v[i] < v[i+1]){
           contCrescente++;
       }
       else{
           contDecrescente++;
       }
   }

   if((contCrescente == tam-1) || (contDecrescente == tam-1)){
       return 1;
   }
   else{
       return 0;
   }

}