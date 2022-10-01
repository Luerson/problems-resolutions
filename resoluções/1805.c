#include <stdio.h>

int main(){
    int max, min;
    unsigned long long soma;

    scanf("%d %d", &min, &max);

    soma = ((unsigned long long)(max + min)*(max - min + 1)) / 2;

    printf("%llu\n", soma);

    return 0;
}
