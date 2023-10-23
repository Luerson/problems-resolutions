#include <stdio.h>
#define MAX 100

int main(){
    float vetorA[MAX];
    int i;

    for(i = 0; i < MAX; i++){
        scanf("%f", &vetorA[i]);
    }

    for(i = 0; i < MAX; i++){
        if(vetorA[i] <= 10){
            printf("A[%d] = %.1f\n", i, vetorA[i]);
        }
    }

    return 0;
}