#include <stdio.h>

int main(){

    int n, i, contador;

    while(scanf("%d", &n) != EOF){
        for(contador = 0; n != 0; n /= 10){
            contador++;
        }

        printf("%d\n", contador);
    }

    return 0;
}