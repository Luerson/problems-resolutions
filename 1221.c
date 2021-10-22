#include <stdio.h>

int main(){
    int valorN, i, contador, valorX;

    scanf("%d", &valorN);

    while(valorN--){
        scanf("%d", &valorX);
        contador = 0;

        for(i = 1; i*i <= valorX && contador < 2; i++){
            if(valorX % i == 0){
                contador++;
            }
        }

        if(contador == 1){
            printf("Prime\n");
        }else{
            printf("Not Prime\n");
        }
    }
    return 0;
}