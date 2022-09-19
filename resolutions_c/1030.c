#include <stdio.h>
#define MAX 10000

/**
 * @brief Esta atribui valor '1' para todos os elementos de Array
 * 
 * @param homem array ao qual se quer atribuir valores 1
 * @param nHomens tamanho do array
 */
void DarValor(int array[], int n){
    int i;

    for(i = 0; i < n; i++){
            array[i] = 1;
        }
}

/**
 * @brief Esta função verifica quantas pessoas continuam vivas
 * 
 * @param homem array que guarda a condição dos homem
 * @param nHomens quantidade de homens para verificar
 * 
 * @return 1: caso haja alguém vivo;
 *         0: caso estejam todos mortos
 */
int VerificaVivos(int homem[], int nHomens){
    int i = 0;

    for(i = 0; i < nHomens; i++){
        if(homem[i] == 1){
            return 1;
        }
    }

    return 0;
}

int main(){
    int NC, n, k, contador, ultimo, run;
    int homem[MAX], i, j;

    scanf("%d", &NC);

    for(i = 1; i <= NC; i++){
        scanf("%d %d", &n, &k);

        contador = k;

        DarValor(homem, n);

        do{
            for(j = 0; j < n; j++){
                if(contador == 1){

                    if(homem[j] == 1){
                        homem[j] = 0;
                        ultimo = j;
                        contador = k;
                    }
                }else{

                    if(homem[j] == 1){
                        contador--;
                    }
                }
            }
        }while(VerificaVivos(homem, n));

        printf("Case %d: %d\n", i, ultimo+1);
    }

    return 0;
}