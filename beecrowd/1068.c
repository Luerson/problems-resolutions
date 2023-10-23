#include <stdio.h>

int main(){
    char letra;

    while((letra = getchar()) != EOF){
        int soma = 0;

        while(letra != '\n'){
            if(letra == '('){
                soma++;
            }else if(letra == ')'){
                soma--;
            }

            if(soma < 0){
                break;
            }

            letra = getchar();
        }

        if(soma == 0){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }

        if(letra != '\n'){
            while(getchar() != '\n');
        }
        
    }

    return 0;
}