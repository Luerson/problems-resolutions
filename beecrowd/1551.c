#include <stdio.h>
#include <ctype.h>
#define ALFABETO 27

int TipoDeFrase(const char *str){
    char alfabeto[ALFABETO] = {"abcdefghijklmnopqrstuvwxyz"};
    int i, j, contador;

    for(i = 0; str[i] != '\0'; i++){
        if( islower(str[i]) ){
            for(j = 0; (alfabeto[j] != str[i]) && (j < ALFABETO-1); j++);

            if(alfabeto[j] == str[i]){
                alfabeto[j] = '0';
            }
        }
    }

    contador = 0;

    for(i = 0; alfabeto[i] != '\0'; i++){
        if(alfabeto[i] == '0'){
            contador++;
        }
    }

    if(contador < 13){
        return 0;
    }else if(contador < 26){
        return 1;
    }else{
        return 2;
    }
}

int main(){
    int t;
    char str[1001];

    scanf("%d%*c", &t);

    while(t--){
        scanf("%[^\n]%*c", str);

        switch(TipoDeFrase(str)){
            case 0:
                printf("frase mal elaborada\n");
                break;
            case 1:
                printf("frase quase completa\n");
                break;
            case 2:
                printf("frase completa\n");
                break;
        }
    }
    
    return 0;
}