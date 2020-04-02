#include <stdio.h>
#include <stdlib.h>

int main(){

    int t, a1, a2, auxA1, auxA2;

    scanf("%d %d %d", &t, &a1, &a2);

    auxA1 = a1;
    auxA2 = a2;

    while(abs(a1-a2) != t){
        if(a1<a2){
            a1 += auxA1;
        }
        else{
            a2 += auxA2;
        }
    }



    printf("%d\n", (a1>a2? a1: a2));

    return 0;
}