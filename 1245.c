#include <stdio.h>
#define MENOR_TAMANHO 30
#define MAIOR_TAMANHO 61

/**
 * @brief Esta função calcula quantos pares podem ser formados com os
 * sapatos fornecidos
 * 
 * @param esq Array que armazena os sapatos de pé esquerdo
 * @param dir Array que armazena os sapatos do pé direito
 * 
 * @return retorna a quantidade de pares de sapato que podem ser formados 
 */
int ContaPares(int esq[], int dir[]){
    int i, contador = 0;

    for(i = MENOR_TAMANHO; i < MAIOR_TAMANHO; i++){
        if(dir[i] != 0 && esq[i] != 0){
            if(dir[i] < esq[i]){
                contador += dir[i];
            }else{
                contador += esq[i];
            }
        }
    }
    return contador;
}

int main(){
    int nBotas;

    while(scanf("%d", &nBotas) != EOF){
        int tamanho, direito[MAIOR_TAMANHO] = {0}, esquerdo[MAIOR_TAMANHO] = {0};
        char lado;
        int i;

        for(i = 0; i < nBotas; i++){
            scanf("%d%*c%c", &tamanho, &lado);

            switch(lado){
                case 'E':
                    esquerdo[tamanho]++;
                    break;
                case 'D':
                    direito[tamanho]++;
                    break;
            }
        }

        printf("%d\n", ContaPares(esquerdo, direito));
    }

    return 0;
}