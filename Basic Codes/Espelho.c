#include <stdio.h>
#include <stdbool.h>

bool Espelho(int n1, int n2){

    if(((n1/1000) == (n2%10)) && (((n1%1000 - n1%100)/100) == ((n2%100 - n2%10)/10)) && (((n1%100 - n1%10)/10) == ((n2%1000 - n2%100)/100)) && ((n1%10) == (n2/1000))){
        return true;
    }
    else{
        return false;
    }

}

int main (){

    int n1, n2, t1, t2, t3, t4, t5, t6, t7, t8;

    scanf("%d %d", &n1, &n2);

    if(Espelho(n1, n2)){
        printf("espelho\n");
    }
    else{
        printf("nao espelho\n");
    }

    return 0;
}