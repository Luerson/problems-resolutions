#include <stdio.h>

int main(){
    int valorX, i, fatorial = 1;

    scanf("%d", &valorX);

    for(i = 1; i <= valorX; i++){
        fatorial *= i;
    }

    printf("%d\n", fatorial);

    return 0;
}