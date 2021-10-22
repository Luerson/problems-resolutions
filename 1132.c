#include <stdio.h>

int main(){
    int maior, menor, soma = 0;
    int valorX, valorY;

    scanf("%d %d", &valorX, &valorY);

    if (valorX > valorY){
        maior = valorX;
        menor = valorY;
    }else{
        maior = valorY;
        menor = valorX;
    }

    do{
        if(menor % 13 == 0){
            continue;
        }
        soma += menor;

    }while(++menor <= maior);

    printf("%d\n", soma);

    return 0;
}