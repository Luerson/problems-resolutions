#include <stdio.h>

int main(){
    int i, j, soma;
    int nTestes, valorX;

    scanf("%d", &nTestes);

    for(i = 1; i <= nTestes; i++){ 
        scanf("%d", &valorX);
        soma = 0;

        for(j = 1; j < valorX; j++){
            if (valorX % j == 0){
                soma += j;
            }
        }

        if(soma == valorX){
            printf("%d eh perfeito\n", valorX);
        }else{
            printf("%d nao eh perfeito\n", valorX);
        }
    }

    return 0;
}