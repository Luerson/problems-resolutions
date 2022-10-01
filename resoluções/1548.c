#include <stdio.h>

int main(){
    int N;

    scanf("%d", &N);

    while(N--){
        int M;

        scanf("%d", &M);
        {
            int fila[M], filaOrd[M], i, aux, troca;
            int contador = 0;

            for(i = 0; i < M; i++){
                scanf("%d", &fila[i]);
                filaOrd[i] = fila[i];
            }

            do{
                troca = 0;
                for(i = 0; i < (M-1); i++){
                    if(filaOrd[i] < filaOrd[i+1]){
                        aux = filaOrd[i];
                        filaOrd[i] = filaOrd[i+1];
                        filaOrd[i+1] = aux;
                        troca = 1; 
                    }
                }
            }while(troca == 1);

            for(i = 0; i < M; i++){
                if(fila[i] == filaOrd[i]){
                    contador++;
                }
            }

            printf("%d\n", contador);
        }
    }

    return 0;
}