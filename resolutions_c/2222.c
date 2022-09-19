#include <stdio.h>
#define MAX_VAL 61

/**
 * @brief Esta função zera todos os valores de um Array
 * 
 * @param ar entrada/saída - o Array
 * @param tamanho entrada - tamanho do Array
 */
void ZeraArray(int ar[], const int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        ar[i] = 0;
    }
}

/**
 * @brief Esta função atribui os valores lidos do teclado para o Array
 * 
 * @param ar entrada/saída - o Array
 * @param tamanho entrada - tamanho do Array
 */
void LerParaArray(int ar[], const int tamanho){
    int i;

    for(i = 1; i < tamanho; i++){
        scanf("%d", &ar[i]);
    }
}

/**
 * @brief Esta função define a interseção de dois Arrays
 * 
 * @param inter entrada/saíde - armazena os valores que fazem parte da 
 * interseção, onde o índice é igual ao valor que se quer armazenar.
 * @param ar1 entrada - primeiro Array
 * @param ar2 entrada - segundo Array
 * @param tamanho entrada - tamanho dos três Arrays
 */
void DefineIntersecao(int inter[], const int ar1[], const int ar2[], const int tamanho){
    int i, j;
    
    for(i = 1; i < tamanho; i++){
        if(ar1[i] != 0){
            for(j = 1; j < tamanho; j++){
                if(ar1[i] == ar2[j]){
                    inter[ar1[i]] = ar1[i];
                }
            }
        }
    }

}

/**
 * @brief Esta função define a união de dois Arrays
 * 
 * @param uniao entrada/saída - armazena os valores que fazem parte da união,
 * onde o índice é igual ao valor que se quer armazenar.
 * @param ar1 entrada - primeiro Array
 * @param ar2 entrada - segundo Array
 * @param tamanho entrada - tamanho dos três Arrays
 */
void DefineUniao(int uniao[], const int ar1[], const int ar2[], const int tamanho){
    int i;

    for(i = 1; i < tamanho; i++){
        if(ar1[i] != 0){
            uniao[ar1[i]] = ar1[i];
        }
    }

    for(i = 1; i < tamanho; i++){
        if(ar2[i] != 0){
            uniao[ar2[i]] = ar2[i];
        }
    }
}

/**
 * @brief Esta função calcula quantos valores diferentes de zero o
 * Array está armazenando
 * 
 * @param ar entrada/saída - o Array
 * @param tamanho entrada - tamanho do Array
 * 
 * @return inteiro não negativo que representa o número de valores
 * diferentes de zero 
 */
int Conta(int ar[], const int tamanho){
    int i, contador = 0;

    for(i = 0; i < MAX_VAL; i++){
        if(ar[i] != 0){
            contador++;
        }
    }

    return contador;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int nConj, mVal, qOperacoes, i;

        scanf("%d", &nConj);
        nConj++;

        int conjunto[nConj][MAX_VAL];

        for(i = 0; i < nConj; i++){
            ZeraArray(&conjunto[i], MAX_VAL);
        }
        
        for(i = 1; i < nConj; i++){
            scanf("%d", &mVal);
            mVal++;

            LerParaArray(&conjunto[i], mVal);
        }

        scanf("%d", &qOperacoes);

        while(qOperacoes--){
            int opTipo, conj1, conj2, contador = 0;
            int intersecao[MAX_VAL], uniao[MAX_VAL];

            ZeraArray(intersecao, MAX_VAL);
            ZeraArray(uniao, MAX_VAL);

            scanf("%d %d %d", &opTipo, &conj1, &conj2);

            switch(opTipo){
                case 1:
                    DefineIntersecao(intersecao, conjunto[conj1], conjunto[conj2], MAX_VAL);
                    contador = Conta(intersecao, MAX_VAL);
                    printf("%d\n", contador);
                    break;

                case 2:
                    DefineUniao(uniao, conjunto[conj1], conjunto[conj2], MAX_VAL);
                    contador = Conta(uniao, MAX_VAL);
                    printf("%d\n", contador);
            }
        }
    }
    return 0;
}
