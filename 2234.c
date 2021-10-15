#include<stdio.h>

int main(){
    double hotdogs, participantes;

    scanf("%lf %lf", &hotdogs, &participantes);
    printf("%.2lf\n", hotdogs / participantes);

    return 0;
}