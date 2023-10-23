#include <stdio.h>

int main(){
    int valorN, i;
    float valorC;

    scanf("%d", &valorN);

    while(valorN--){
        scanf("%f", &valorC);

        for(i = 0; valorC > 1; i++){
            valorC /= 2;
        }

        printf("%d dias\n", i);
    }
    return 0;
}