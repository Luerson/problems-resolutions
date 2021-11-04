#include <stdio.h>
#define MAX 10001

int main(){
    while(1){
        int n, m, bilhete;
        int frequencia[MAX] = {0}, contador = 0, i;

        scanf("%d %d", &n, &m);

        if(n == 0 && m == 0){
            break;
        }

        for(i = 0; i < m; i++){
            scanf("%d", &bilhete);
            frequencia[bilhete]++;
        }

        for(i = 1; i < n+1; i++){
            if(frequencia[i] > 1){
                contador++;
            }
        }

        printf("%d\n", contador);
    }
    return 0;
}