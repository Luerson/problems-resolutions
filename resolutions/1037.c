#include <stdio.h>

int main(){
    float valorX;

    scanf("%f", &valorX);

    if((valorX < 0) || (valorX > 100)){
        printf("Fora de intervalo\n");
    }else if(valorX <= 25){
        printf("Intervalo [0,25]\n");
    }else if(valorX <= 50){
        printf("Intervalo (25,50]\n");
    }else if(valorX <= 75){
        printf("Intervalo (50,75]\n");
    }else if(valorX <= 100){
        printf("Intervalo (75,100]\n");
    }

    return 0;
}