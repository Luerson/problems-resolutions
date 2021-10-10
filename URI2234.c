#include<stdio.h>

int main(){
    double hotdogs, participantes;
    double media;

    scanf("%lf %lf", &hotdogs, &participantes);

    media = hotdogs / participantes;

    printf("%.2lf\n", media);

    return 0;
}