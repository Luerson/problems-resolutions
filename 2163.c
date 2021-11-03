#include <stdio.h>
#define SINAL_SABRE 42

/**
 * @brief Esta função calcula se o valor representa um sabre de luz
 * 
 * @param coluna a quantidade de colunas que a matriz que representa o terreno
 * possui
 * @param terreno array que armazena os valores do terreno
 * @param i linha do valor ue se quer verificar
 * @param j coluna do valor que se quer verificar
 * 
 * @return 1: se o valor for de um dabre de luz
 *         0: se o valor não for de um sabre de luz
 */
int EhSabre(int coluna, int terreno[][coluna], int i, int j){
    if(terreno[i][j] != SINAL_SABRE){
        return 0;
    }

    int sinalX, sinalY;

    sinalX = i;
    sinalY = j;

    for(i -= 1; i < (sinalX + 2); i++){
        for(j -= 1; j < (sinalY + 2); j++){
            if(terreno[i][j] != 7){
                if((i != sinalX) && (j != sinalY)){
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

int main(){
    int linha, coluna, x, y;

    scanf("%d %d", &linha, &coluna);

    {
        int terreno[linha][coluna], i, j;
        x = y = 0;

        for(i = 0; i < linha; i ++){
            for(j = 0; j < coluna; j++){
                scanf("%d", &terreno[i][j]);
            }
        }

        for(i = 1; i < (linha-1); i++){
            for(j = 1; j < (coluna-1); j++){
                if(EhSabre(coluna, terreno, i, j) == 1){
                    x = i+1;
                    y = j+1;
                    break;
                }  
            }

            if(x != 0 || y != 0){
                break;
            }
        }

        printf("%d %d\n", x, y);
    }

    return 0;
}