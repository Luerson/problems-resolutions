#include <stdio.h>

int main(){
    int valorX, i;

    scanf("%d", &valorX);

    for(i = 1; i <= valorX; i++){
        if(valorX % i == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}