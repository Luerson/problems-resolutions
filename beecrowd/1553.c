#include <stdio.h>
#define MAX 101

int main(){
    while(1){
        int i, n, k, frequencia[MAX] = {0}, contador, pergunta;

        scanf("%d %d", &n, &k);

        if((n == 0) && (k == 0)){
            break;
        }

        for(i = 0; i < n; i++){
            scanf("%d", &pergunta);
            frequencia[pergunta]++;
        }

        contador = 0;

        for(i = 1; i < MAX; i++){
            if(frequencia[i] >= k){
                contador++;
            }
        }

        printf("%d\n", contador);
    }
    
    return 0;
}