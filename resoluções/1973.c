#include <stdio.h>

int EhPar(numero){
    return numero % 2 == 0;
}

int main(){
    int N;

    scanf("%d", &N);

    int estrela[N], i, maiorEstrela;
    unsigned long long soma;

    maiorEstrela = soma = 0;

    for(i = 0; i < N; i++){
        scanf("%d", &estrela[i]);
    }

    for(i = 0; i < N && i >= 0;){
        if(i > maiorEstrela){
            maiorEstrela = i;
        }

        if(EhPar(estrela[i])){
            i -= 1;

            if(estrela[i+1] > 0){
            estrela[i+1] -= 1;
            } 
        }else{
            i += 1;

            if(estrela[i-1] > 0){
            estrela[i-1] -= 1;
            } 
        }
    }

    for(i = 0; i < N; i++){
        soma += estrela[i];
    }

    printf("%d %llu\n", maiorEstrela+1, soma);

    return 0;
}