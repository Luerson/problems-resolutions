#include <stdio.h>
#include <math.h>

/**
 * @brief Esta função calcula o peso dos grãos que serão
 * colocados no tabuleiro 
 * 
 * @param nCasas numero de casas do tabuleiro de damas
 * 
 * @return retorna o peso total dos grãos em quilos(Kg) 
 */
unsigned long long GraosNoTabuleiro(const unsigned long long nCasas){
    unsigned long long graos;

    graos = pow(2, nCasas) - 1;

    return graos/12000;
}

int main(){
    int N, valorX;

    scanf("%d", &N);

    while(N--){
        scanf("%d", &valorX);

        printf("%llu kg\n", GraosNoTabuleiro(valorX));
    }

    return 0;
}