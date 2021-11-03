#include <stdio.h>

int main(){
    int N;

    scanf("%d", &N);
    {
        int vetorX[N], menor, posicao, i;

        scanf("%d", &vetorX[0]);

        menor = vetorX[0];
        posicao = 0;

        for(i = 1; i < N; i++){
            scanf("%d", &vetorX[i]);

            if(vetorX[i] < menor){
                menor = vetorX[i];
                posicao = i;
            }
        }

        printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
    }

    return 0;
}