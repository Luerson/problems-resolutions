#include <stdio.h>

int EhPar(int numero){
    return numero % 2 == 0;
}

/**
 * @brief [Essa função calcula o valor total do golpe do pomekon]
 * 
 * @param ataque [Corresponde ao valor de ataque do pomekon]
 * @param defesa [Corresponde ao valor de defesa do pomekon]
 * @param nivel [Nível do treinador do pomekon]
 * @param bonus [Caso o nível do treinador seja par, o valor bônus deve ser 
 * acrescido ao ValorGolpe calculado]
 *  
 * @return [Os resultados esperados são valores reais maiores que zero]
 */
float ValorGolpe(int ataque, int defesa, int nivel, int bonus){
    if(EhPar(nivel)){
        return ((ataque + defesa) / 2) + bonus;
    }else{
        return (ataque + defesa) / 2;
    }
}

int main(){
    int valorT, bonus, ataque, defesa, nivel;//entrada
    int valorGolpeD, valorGolpeG;//saída

    scanf("%d", &valorT);

    while(valorT--){
        scanf("%d", &bonus);

        scanf("%d %d %d", &ataque, &defesa, &nivel);
        valorGolpeD = ValorGolpe(ataque, defesa, nivel, bonus);

        scanf("%d %d %d", &ataque, &defesa, &nivel);
        valorGolpeG = ValorGolpe(ataque, defesa, nivel, bonus);

        if(valorGolpeD == valorGolpeG){
            printf("Empate\n");
        }else if(valorGolpeD > valorGolpeG){
            printf("Dabriel\n");
        }else{
            printf("Guarte\n");
        }
    }

    return 0;
}