#include <stdio.h>

int main(){
    int nValores, valorX;
    int i, contador = 0;

    scanf("%d", &nValores);

    for(i = 0; i < nValores; i++){
        scanf("%d", &valorX);
        
        if(valorX >= 10 && valorX <= 20){
            contador++;
        }
    }

    printf("%d in\n%d out\n", contador, i - contador);

    return 0;
}