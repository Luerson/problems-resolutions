#include <stdio.h>

/**
 * @brief Calcula o número de leds necessários para formar a string
 * 
 * @param str a string
 * 
 * @return Retorna um inteiro não negativo que representa o número
 * de leds.
 */
int TotalDeLeds(const char *str){
    int i, contador = 0;

    for(i = 0; str[i] != '\0'; i++){
        switch(str[i]){
            case '8':
                contador += 7;
                break;
            case '0':
            case '9':
            case '6':
                contador += 6;
                break;
            case '2':
            case '3':
            case '5':
                contador += 5;
                break;
            case '4':
                contador += 4;
                break;
            case '7':
                contador += 3;
                break;
            case '1':
                contador += 2;
                break;
        }
    }

    return contador;
}

int main(){
    int nTestes, total_de_leds;
    char str[102];

    scanf("%d%*c", &nTestes);

    while(nTestes--){
        scanf("%s", str);

        total_de_leds = TotalDeLeds(str);

        printf("%d leds\n", total_de_leds);
    }

    return 0;
}