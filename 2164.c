#include <stdio.h>
#include <math.h>
#define RAIZ_DE_5 sqrt(5)

/**
 * @brief Esta função calcula o valor numa determinada posição em fibonacci
 * conforme a "fórmula de Binet"
 * 
 * @param posicao a posição que o valor ocupa na sequência de fibonacci
 * 
 * @return retorna o valor correspondente à posição fornecida, considerando
 * que a sequência de fibonacci começa em 1.
 */
double ValorEmFibo(int posicao){
    double x1, x2;

    x1 = (1+RAIZ_DE_5)/2;
    x2 = (1-RAIZ_DE_5)/2;

    return (pow(x1, posicao) - pow(x2, posicao))/ RAIZ_DE_5;
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%.1lf\n", ValorEmFibo(n));

    return 0;
}