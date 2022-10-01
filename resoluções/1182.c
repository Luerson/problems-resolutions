#include <stdio.h>

int main(){
    int coluna, i, j;
    float matriz[12][12], soma;
    char c;

    scanf("%d%*c", &coluna);
    scanf("%c", &c);

    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

    soma = 0;

    for(i = 0; i < 12; i++){
        soma += matriz[i][coluna];
    }

    if(c == 'S'){
        printf("%.1f\n", soma);
    }else{
        printf("%.1f\n", soma/12);
    }

    return 0;
}