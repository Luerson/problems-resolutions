#include <stdio.h>

/**
 * @brief Esta função atribui os valores digitados ao Array
 * 
 * @param ar o array ao qual se quer atribuir valores
 * @param t tamanho do array
 */
void LerArray(int ar[], const int t){
    int i;
    for(i = 0; i < t; i++){
        scanf("%d", &ar[i]);
    }
}

/**
 * @brief Esta função calcula o menor valor do Array que é diferente de zero
 * 
 * @param ar array que se que encontrar o menor valor
 * @param t tamanho do Array
 * 
 * @return menor valor diferente de zero(se houver);
 *         0: se todos os valores forem zero; 
 */
int MenorValor(const int ar[], const int t){
    int i, menorValor = 0;

    for(i = 0; i < t; i++){
        if(ar[i] != 0){
            if(menorValor == 0){
                menorValor = ar[i];
            }else{
                if(ar[i] < menorValor){
                    menorValor = ar[i];
                }
            }
        }
    }

    return menorValor;
}

/**
 * @brief Esta função calcula quantas vezes um determinado valor 
 * aparece no Array
 * 
 * @param ar Array de interesse
 * @param t tamanho do Array
 * @param valor valor especifico que se quer verificar
 * 
 * @return retorna um número intiro não negativo 
 */
int NVezes(int ar[], const int t, const int valor){
    int i, contador = 0;

    for(i = 0; i < t; i++){
        if(ar[i] == valor){
            contador++;
            ar[i] = 0;
        }
    }

    return contador;
}

int main(){
    int N;

    scanf("%d", &N);
    {
        int vetorX[N], i, menorValor, contador;

        LerArray(vetorX, N);

        while(menorValor = MenorValor(vetorX, N)){

            contador = NVezes(vetorX, N, menorValor);

            printf("%d aparece %d vez(es)\n", menorValor, contador);
        }
    }

    return 0;
}