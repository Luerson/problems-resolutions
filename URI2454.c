#include<stdio.h>

int main(){
    int valorDeP, valorDeR;

    scanf("%d %d", &valorDeP, &valorDeR);

    if(valorDeP == 0){
        printf("C\n");
    }else if(valorDeR == 0){
        printf("B\n");
    }else{
        printf("A\n");
    }

    return 0;
}