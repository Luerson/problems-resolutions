#include <stdio.h>

int main(){
    int nTestes, quantia;
    int somaS, somaC, somaR;
    char tipo;

    scanf("%d", &nTestes);
    somaS = somaC = somaR = 0;

    while(nTestes--){
        scanf("%d%*c", &quantia);
        scanf("%c", &tipo);

        switch(tipo){
            case 'S':
                somaS += quantia;
                break;
            case 'C':
                somaC += quantia;
                break;
            case 'R':
                somaR += quantia;
                break;
        }
    }

    printf("Total: %d cobaias\n", somaR + somaS + somaC);
    printf("Total de coelhos: %d\n", somaC);
    printf("Total de ratos: %d\n", somaR);
    printf("Total de sapos: %d\n", somaS);
    printf("Percentual de coelhos: %.2f %%\n", 100.0*somaC / (somaR + somaS + somaC));
    printf("Percentual de ratos: %.2f %%\n", 100.0*somaR / (somaR + somaS + somaC));
    printf("Percentual de sapos: %.2f %%\n", 100.0*somaS / (somaR + somaS + somaC));

    return 0;
}