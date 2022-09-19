#include <stdio.h>

/**
 * @brief Verifica se a string é uma senha válida(uma senha válida possui
 * PELO MENOS uma letra minúscula, uma maiúscula e um número, possui APENAS 
 * letras e números e entre 6 e 32 caracteres)
 * 
 * @param str entrada - a string
 * 
 * @return 1: se a senha for válida
 *         0: se a senha não for válida por qualquer motivo
 */
int SenhaValida(const char *str){
    int i, cont_A, cont_a, cont_1, tamanho;
    int caracteres_validos, senha_suficiente, tamanho_correto;

    cont_A = cont_a = cont_1 = tamanho = 0;

    for(i = 0; str[i] != '\0'; i++){
        if( (str[i] >= 'a') && (str[i] <= 'z')){
            cont_a++;

        }else if( (str[i] >= 'A') && (str[i] <= 'Z')){
            cont_A++;

        }else if( (str[i] >= '0') && (str[i] <= '9')){
            cont_1++;
        }

        tamanho++;
    }

    if(tamanho >= 6 && tamanho <= 32){
        tamanho_correto = 1;
    }else{
        tamanho_correto = 0;
    }

    if(tamanho == cont_A + cont_a + cont_1){
        caracteres_validos = 1;
    }else{
        caracteres_validos = 0;
    }

    if( (cont_A > 0) && (cont_a > 0) && (cont_1 > 0)){
        senha_suficiente = 1;
    }else{
        senha_suficiente = 0;
    }

    if(caracteres_validos && senha_suficiente && tamanho_correto){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char str[150];

    while(scanf("%[^\n]%*c", str) != EOF){
        
        if(SenhaValida(str)){
            printf("Senha valida.\n");
        }else{
            printf("Senha invalida.\n");
        }
    }

    return 0;
}