#include <stdio.h>
#include <stdbool.h>

bool Possivel(int n, int v){

    int i, cont = 0, v2 =v;

    while(v2 != 0){
       for(i=0; i<v; i++){
            if(cont == n){
                return true;
            }
            cont += v;
        }
        v--;

        if(cont == n){
            return true;
        }

        if(v == 0){
            v2--;
            v = v2;
            cont = 0;
        }

    }

    if(cont == n){
        return true;
    }
    else{
        return false;
    }

}

int main(){

    int n=1, v=1;

    while((n != 0) && (v!=0)){
        scanf("%d %d", &n, &v);
        if((n == 0) && (v==0)){
            return 0;
        }
        else if(Possivel(n, v)){
            printf("possivel\n");
        }
        else{
            printf("impossivel\n");
        }
    }

    return 0;
}