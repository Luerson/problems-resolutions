#include <stdio.h>
#define MAX 20

int main(){
    int vetorN[MAX], i, aux;

    for(i = 0; i < MAX; i++){
        scanf("%d", &vetorN[i]);
    }

    for(i = 0; i < (MAX/2); i++){
        aux = vetorN[i];
        vetorN[i] = vetorN[MAX - (i + 1)];
        vetorN[MAX - (i + 1)] = aux;
    }

    for(i = 0; i < MAX; i++){
        printf("N[%d] = %d\n", i, vetorN[i]);
    }

    return 0;
}