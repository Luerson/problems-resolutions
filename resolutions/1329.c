#include <stdio.h>

int main(){
    int coroa, nJogos;
    int contadorJ, contadorM;

    while(1){
        scanf("%d", &nJogos);
        if(nJogos == 0){
            break;
        }

        contadorM = contadorJ = 0;

        while(nJogos--){
            scanf("%d", &coroa);

            if(coroa){
                contadorJ++;
            }else{
                contadorM++;
            }
        }

        printf("Mary won %d times ", contadorM);
        printf("and John won %d times\n", contadorJ);
    }

    return 0;
}