#include <stdio.h>

int main(){
    int N, i;
    int fatorial, contador = 0;;

    scanf("%d", &N);
    i = fatorial = 1;

    do{
        if(fatorial*(i+1) > N){
            N -= fatorial;
            i = 1;
            fatorial = 1;
            contador++;
        }else{
            i++;
            fatorial *= i;
        }
    }while(N != 0);

    printf("%d\n", contador);

    return 0;
}