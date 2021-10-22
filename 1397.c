#include <stdio.h>

int main(){
    int valorN, og, filho;
    int contadorO, contadorF;

    while(1){
        scanf("%d", &valorN);

        if(valorN == 0){
            break;
        } 

        contadorO = contadorF = 0;

        while(valorN--){
            scanf("%d %d", &og, &filho);

            if(og > filho){
                contadorO++;
            }else if(filho > og){
                contadorF++;
            }
        }

        printf("%d %d\n", contadorO, contadorF);
    }

    return 0;
}