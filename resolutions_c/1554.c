#include <stdio.h>
#include <math.h>

/**
 * @brief Esta função calcula a distância entre dois pontos em um plano
 * cartesiano.
 * 
 * @param x0 abscissa do primeiro ponto
 * @param y0 ordenada do primeiro ponto
 * @param x1 abscissa do segundo ponto
 * @param y1 ordenada do segundo ponto
 * 
 * @return Apenas reais iguais ou superiores a zero. 
 */
float DistPontos(int x0, int y0, int x1, int y1){
    int catetoX, catetoY;

    catetoX = x1 - x0;
    catetoY = y1 - y0;

    return sqrt(catetoX*catetoX + catetoY*catetoY);

}

int main(){
    int valorC, valorN, xBranca, xDaBola;
    int yBranca, yDaBola, i, menorDist, nDaMenor;
    float distPontos;

    scanf("%d", &valorC);

    while(valorC--){
        scanf("%d %d %d", &valorN, &xBranca, &yBranca);
        scanf("%d %d", &xDaBola, &yDaBola);
        
        menorDist = DistPontos(xBranca, yBranca, xDaBola, yDaBola);
        nDaMenor = 1;

        for(i = 2; i <= valorN; i++){
            scanf("%d %d", &xDaBola, &yDaBola);
            distPontos = DistPontos(xBranca, yBranca, xDaBola, yDaBola);

            if(distPontos < menorDist){
                menorDist = distPontos;
                nDaMenor = i;
            }
        }

        printf("%d\n", nDaMenor);
    }

    return 0;
}