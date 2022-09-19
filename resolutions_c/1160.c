#include <stdio.h>

int main(){
    int valorT, popA, popB, i;
    double taxaA, taxaB;

    scanf("%d", &valorT); 

    while(valorT--){
        scanf("%d %d %lf %lf", &popA, &popB, &taxaA, &taxaB);

        for(i = 0; popA <= popB && i <= 100; i++){
            (int)(popA *= (100 + taxaA)/100);
            (int)(popB *= (100 + taxaB)/100);
        }

        if(i > 100){
            printf("Mais de 1 seculo.\n");
        }else{
            printf("%d anos.\n", i);
        }
    }

    return 0;
}