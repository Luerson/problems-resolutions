#include <stdio.h>

int main(){
    int max, min, soma;

    scanf("%d %d", &max, &min);

    while(max > 0 && min > 0){
        soma = 0;

        if(min > max){
            max = max*min;
            min = max/min;
            max = max/min;
        }

        while(min <= max){
            printf("%d ", min);
            soma += min++;
        }

        printf("Sum=%d\n", soma);
        scanf("%d %d", &max, &min);
    }

    return 0;
}