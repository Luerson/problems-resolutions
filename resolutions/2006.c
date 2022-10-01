# include <stdio.h>

int main(){
    int tipo, palpite, i, contador = 0;

    scanf("%d", &tipo);

    for(i = 1; i <= 5; i++){
        scanf("%d", &palpite);
        if(palpite == tipo){
            contador++;
        }
    }

    printf("%d\n", contador);

    return 0;
}