#include <stdio.h>

int Rafael(int x, int y){
    return 9*x*x + y*y;
}

int Beto(int x, int y){
    return 2*x*x + 25*y*y;
}

int Carlos(int x, int y){
    return -100*x + y*y*y;
}

int main(){
    int testes, valorX, valorY;
    int rafael, beto, carlos;  

    scanf("%d", &testes);

    while(testes--){
        scanf("%d %d", &valorX, &valorY);

        rafael = Rafael(valorX, valorY);
        beto = Beto(valorX, valorY);
        carlos = Carlos(valorX, valorY);

        if(rafael > beto && rafael > carlos){
            printf("Rafael ganhou\n");
        }else if(beto > carlos){
            printf("Beto ganhou\n");
        }else{
            printf("Carlos ganhou\n");
        }
    }

    return 0;
}