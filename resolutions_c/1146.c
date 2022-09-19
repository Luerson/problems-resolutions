#include <stdio.h>

int main(){
    int valorX, i;

    while(1){
        scanf("%d", &valorX);

        if(valorX == 0){
            break;
        }

        printf("1");

        for(i = 2; i <= valorX; i++){
            printf(" %d", i);
        }

        printf("\n");
    }

    return 0;
}