#include <stdio.h>

/**
 * @brief calcula o avlor correspondente a uma determinada posição 
 * n asequência de fibonacci
 * 
 * @param posicao posição do número na sequência de fibonacci
 * @param call adiciona 1 na quantidade total de chamadas da função
 * 
 * @return o valor correspondente á posição dada 
 */
unsigned long long Fibo(int posicao, unsigned long long *call){
    *call += 1;

    if(posicao == 1){
        return 1;
    }
    if(posicao == 0){
        return 0;
    }
    return Fibo(posicao-1, call) + Fibo(posicao-2, call);
}

int main(){
    int n, numero;
    unsigned long long fibo, call;

    scanf("%d", &n);

    while(n--){
        scanf("%d", &numero);

        call = 0;
        fibo = Fibo(numero, &call);

        printf("fib(%d) = %llu calls = %llu\n", numero, call-1, fibo);
    }

    return 0;
}