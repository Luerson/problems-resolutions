#include <stdio.h>

int main(){
    int i, valorN, j;
    float valorC;

    scanf("%d", &valorN);

    for(i = 1; i <= valorN; i++){
        scanf("%f", &valorC);

        for(j = 0; valorC > 1; j++){
            valorC /= 2;
        }

        printf("%d dias\n", j);
    }
    return 0;
}