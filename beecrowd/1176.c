#include <stdio.h>

/**
 * @brief Esta função calcula o valor de fibonacci em uma determinada posição
 * 
 * @param posicao corresponde à posição na sequência de fibonacci do valor que
 * se quer calcular. '0' = primeira posição, '1' = segunda posição...
 * 
 * @return valores naturais da sequência de fibonacci
 */
unsigned long long ValorDaPosicao(int posicao){
    unsigned long long novo = 1, anterior = 0;

    if(posicao == 0){
        return 0;
    }

    posicao -= 1;

    while(posicao--){           
        novo += anterior;
        anterior = novo - anterior;
    }
    
    return novo;
}

int main(){
    int valorT, posicao;//entrada

    scanf("%d", &valorT);

    while(valorT--){
        scanf("%d", &posicao);
        printf("Fib(%d) = %llu\n", posicao, ValorDaPosicao(posicao));
    }

    return 0;
}