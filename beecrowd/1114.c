#include <stdio.h>

int main(){
    int senha, senhaCorreta;

    scanf("%d", &senha);

    senhaCorreta = 2002;

    while(senha != senhaCorreta){
        printf("Senha Invalida\n");
        scanf("%d", &senha);
    }

    printf("Acesso Permitido\n");

    return 0;
}