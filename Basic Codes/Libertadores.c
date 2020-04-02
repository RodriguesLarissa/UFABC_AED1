#include <stdio.h>

int main(){

    int n, i, t1, t2, time1, time2, p1, p2;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        p1 = p2 = 0;
        scanf("%d x %d", &t1, &t2);

        if(t1 > t2){
            p1 += 3;
        }
        else if(t2 > t1){
            p2 += 3;
        }
        else{
            p1++;
            p2++;
        }

        scanf("%d x %d", &time2, &time1);

        if(time1 > time2){
            p1 += 3;
        }
        else if(time2 > time1){
            p2 += 3;
        }
        else{
            p1++;
            p2++;
        }

        if(p1 > p2){
            printf("Time 1\n");
        }
        else if(p2 > p1){
            printf("Time 2\n");
        }
        else{
            if((t1+time1) > (t2+time2)){
                printf("Time 1\n");
            }
            else if((t2+time2) > (t1+time1)){
                printf("Time 2\n");
            }
            else if(time1 > t2){
                printf("Time 1\n");
            }
            else if(t2 > time1){
                printf("Time 2\n");
            }
            else{
                printf("Penaltis\n");
            }
        }

    }

    return 0;
}