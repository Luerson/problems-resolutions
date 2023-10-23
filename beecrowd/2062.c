#include <stdio.h>
#include <string.h>

/**
 * @brief muda o '\n' no final da string para '\0', caso exista
 * 
 * @param str entrada/saída - a string
 */
void Trim(char *str){
    if( str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
}

/**
 * @brief Corrige o texto
 * 
 * @param texto entrada/saída - a string texto
 * @param erro a expressão que se quer verificar
 */
void Corretor(char *texto, const char *erro){
    char *ultimo_caract, *averiguador;
    int continua;

    averiguador = texto;

    while(1){
        averiguador = strstr(averiguador, erro);

        if(averiguador == NULL){
            break;
        }

        /*este 'if' verifica se a palavra possui apenas três caracteres,
        condição necessária para modificá-la a 'URI' ou 'OBI'*/
        if((averiguador[3] == ' ') || (averiguador[3] == '\0') ){
            if( (averiguador == &texto[0]) || (averiguador[-1] == ' ')){
                averiguador[2] = 'I';
            }
        }
        
        averiguador += 1;
    }
}

int main(){
    int max_caract;

    {
        int max_palavras;

        scanf("%d%*c", &max_palavras);

        max_caract = (max_palavras*21) + 1;
    }

    char texto[max_caract];

    fgets(texto, max_caract, stdin);
    Trim(texto);

    Corretor(texto, "OB");
    Corretor(texto, "UR");

    printf("%s\n", texto);

    return 0;
}