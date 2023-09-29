#include <stdio.h>

int main(){
    int i, posicao;
    int valorX, max = 0;

    for(i = 0; i < 100; i++){
        scanf("%d", &valorX);

        if(valorX > max){
            max = valorX;
            posicao = i + 1;
        }
    }

    printf("%d\n%d\n", max, posicao);

    return 0;
}