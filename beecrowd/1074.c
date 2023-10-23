#include <stdio.h>

int main(){
    int valorN, numero;
    int i, numeroImpar;

    scanf("%d", &valorN);

    for(i = 1; i <= valorN; i = i + 1){
        scanf("%d", &numero);
        numeroImpar = numero % 2;

        if (numero == 0){
            printf("NULL\n");
        }else{
            
            if(numeroImpar){
                printf("ODD ");
            }else {
                printf("EVEN ");
            }

            if(numero > 0){
                printf("POSITIVE\n");
            }else{
                printf("NEGATIVE\n");
            }
        }
     
    }

    return 0;
}