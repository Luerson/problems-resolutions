#include <stdio.h>

int main(){
    int valorX, fatorial = 1;

    scanf("%d", &valorX);

    while(valorX--){
        fatorial *= valorX + 1;
    }

    printf("%d\n", fatorial);

    return 0;
}