#include <stdio.h>
#define MAX 10

int main(){
    int i, vetorN[MAX];
    {
        int valor1;

        scanf("%d", &valor1);
        vetorN[0] = valor1;
    }

    for(i = 1; i < MAX; i++){
        vetorN[i] = vetorN[i - 1]*2;
    }

    for(i = 0; i < MAX; i++){
        printf("N[%d] = %d\n", i, vetorN[i]);
    }

    return 0;
}