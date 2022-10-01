#include <stdio.h>
#define MAX 1000

int main(){
    int N, valor[MAX], i;
    int mult2, mult3, mult4, mult5;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &valor[i]);
    }

    mult2 = mult3 = mult4 = mult5 = 0;

    for(i = 0; i < N; i++){
        if(valor[i] % 2 == 0){
            mult2++;
            if(valor[i] % 4 == 0){
                mult4++;
            }
        }

        if(valor[i] % 3 == 0){
            mult3++;
        }

        if(valor[i] % 5 == 0){
            mult5++;
        }
    }

    printf("%d Multiplo(s) de 2\n"
           "%d Multiplo(s) de 3\n"
           "%d Multiplo(s) de 4\n"
           "%d Multiplo(s) de 5\n", mult2, mult3, mult4, mult5);

    return 0;
}