#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Senha(int n){

    if((n%10) == 0){
        return false;
    }
    else if((n%100 - n%10) == 0){
        return false;
    }
    else if((n%1000 - n%100) == 0){
        return false;
    }
    else if((n/1000) == 0){
        return false;
    }
    else{
        return true;
    }

}

int main(){

    int numero;

    scanf("%d", &numero);

    if(Senha(numero)){
        printf("SIM\n");
    }
    else{
        printf("NAO\n");
    }

    return 0;
}