#include <stdio.h>

int main(){
    int valorA, valorB, valorC, valorD;
    int aImpar, somaCD, somaAB; 

    scanf("%d %d %d %d", &valorA, &valorB, &valorC, &valorD);

    aImpar = valorA % 2;
    somaCD = valorC + valorD;
    somaAB = valorA + valorB;

    if((aImpar) || (valorD <= 0) || (valorC <= 0)){
        printf("Valores nao aceitos\n");
    }else if((somaCD <= somaAB) || (valorD <= valorA) || (valorB <= valorC)){
        printf("Valores nao aceitos\n");
    }else{
        printf("Valores aceitos\n");
    }

    return 0;
}