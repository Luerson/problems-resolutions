#include <stdio.h>
#include <string.h>

/**
 * @brief Corrige a palavra com repetição(se houver)
 * 
 * @param str entrada/saída - a palavra
 */
void ApagaRepeticao(char *str){
    int i, tamanho;
    char *substr, *teste;

    tamanho = strlen(str);

    /*Esse 'for' busca o trecho repetido através de substring no final
    da string original. Ex: banana : substr = "a", substr = "na",
    substr = "ana"...*/
    for(i = tamanho-1; i >= 0; i--){
        substr = &str[i];

        if( (i - (int)strlen(substr)) < 0 ) break;

        /*aqui será guardado o endereço onde se supõe começar a parte repetida
        da palavra. 
        Ex1: para str "cavalolo" e substr "lo", teste = "lolo"('lo' e  'lo' são
            iguais, portanto, há repetição)
        Ex2: para str "cavalo" e substr "alo", teste = "cavalo"('cav' e  'alo' são
            diferentes, portanto, não há repetição)*/
        teste = substr - strlen(substr); 
            
        if(teste == strstr(teste, substr)){
            *substr = '\0';
        }
    }
}

int main(){
    char str[31];

    while(scanf("%s", str) != EOF){
        ApagaRepeticao(str);

        printf("%s\n", str);
    }
    return 0;
}