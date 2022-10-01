#include <stdio.h>

int main(){
    int i, j, nDivisores;
    int nTestes, valorX;

    scanf("%d", &nTestes);

    for(i = 1; i <= nTestes; i++){
        scanf("%d", &valorX);
        nDivisores = 0;

        for(j = 1; j <= valorX; j++){         
            if(valorX % j == 0){
                nDivisores++;
            }
        }

        if(nDivisores == 2){
            printf("%d eh primo\n", valorX);
        }else{
            printf("%d nao eh primo\n", valorX);
        }
    }

    return 0;
}