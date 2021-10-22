#include <stdio.h>

int main(){
    int valorT, valorN, valorM;
    int peso, soma, viagens;

    scanf("%d", &valorT);

    while(valorT--){
        scanf("%d %d", &valorN, &valorM);
        soma = 0;
        viagens = 0;

        while(valorN--){
            scanf("%d", &peso);
            soma += peso;

            if(soma >= valorM){
                viagens++;
                (soma == valorM)? (soma = 0) : (soma = peso);
            }
        }

        if(soma == 0){
            printf("%d\n", viagens);
        }else{
            printf("%d\n", viagens + 1);
        }
    }
    
    return 0;
}