#include <stdio.h>

/**
 * @brief Esta função calcula o fatorial de um número
 * 
 * @param numero número que se quer calcular o fatorial
 * 
 * @return naturais que cabem em variáveis long long
 */
long long Fatorial(int numero){
    long long fatorial = 1;

    while(numero--){
        fatorial *= (numero + 1);
    }

    return fatorial;

}

int main(){
    int valorN, valorM, i;
    long long soma = 0;

    while(scanf("%d %d", &valorN, &valorM) != EOF){
        soma = 0;

        soma += Fatorial(valorN) + Fatorial(valorM); 

        printf("%lld\n", soma);
    }

    return 0;
}