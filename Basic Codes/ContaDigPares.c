#include <stdio.h>

int main(){

    int n, contador;

    while(scanf("%d", &n) != EOF){
        for(contador=0; n != 0; n /= 10){
            if((n%10)%2 == 0){
                contador++;
            }
        }
        printf("%d\n", contador);
    }

    return 0;
}