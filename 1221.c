#include <stdio.h>

/**
 * @brief esta função 
 * 
 * @param numero 
 * 
 * @return int 
 */
int EhPrimo(int numero){
    int i, contador;

    for(i = 1; i*i <= numero && contador < 2; i++){
        if(numero % i == 0){
            contador++;
        }
    }

    if(contador == 1 && numero != 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int valorN, valorX;

    scanf("%d", &valorN);

    while(valorN--){
        scanf("%d", &valorX);

        if(EhPrimo(valorX)){
            printf("Prime\n");
        }else{
            printf("Not Prime\n");
        }
    }
    return 0;
}