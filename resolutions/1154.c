#include <stdio.h>

int main(){
    int idade, soma, nIdades;

    soma = nIdades = idade = 0;

    do{
        soma += idade;
        nIdades++;
        scanf("%d", &idade);
    }while(idade >= 0);

    printf("%.2f\n", soma*1.0 / --nIdades);

    return 0;

}