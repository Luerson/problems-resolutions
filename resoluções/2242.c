#include <stdio.h>

/**
 * @brief Define se um caractere é consoante ou não
 * 
 * @param c entrada - o caractere
 * 
 * @return 0: se for vogal
 *         1: se for consoante 
 */
int EhConsoante(const char c){
    switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 0;
        default: 
            return 1;
    }
}

/**
 * @brief Verifica se a risada(string) é ou não engraçada
 * 
 * @param str entrada - a srting
 * 
 * @return 1: se a risada for engraçada
 *         0: se a risada não for engraçada
 */
int RisadaEngracada(const char *str){
    int i = 0, j = 49;

    while(i < j){

        while(EhConsoante(str[i])){
            i++;
        }

        while(EhConsoante(str[j])){
            j--;
        }

        if(str[i] != str[j]){
            return 0;
        }
        j--;
        i++;
    }

    return 1;
}

int main(){
    char str[51] = {0};

    scanf("%[^\n]%*c", str);

    if(RisadaEngracada(str)){
        printf("S\n");
    }else{
        printf("N\n");
    }

    return 0;
}