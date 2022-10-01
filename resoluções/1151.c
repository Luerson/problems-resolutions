#include <stdio.h>

int main(){
    int valorN;
    unsigned long long anterior = 0, novo = 1;

    scanf("%d", &valorN);
    printf("0");

    valorN -= 1;

    while(valorN--){
        printf(" %llu", novo);
        novo += anterior;
        anterior = novo - anterior;
    }

    printf("\n");
    
    return 0;
}