#include <stdio.h>

int main(){
    int nTestes, i;
    int raio1, raio2;

    scanf("%d", &nTestes);

    for (i = 1; i <= nTestes; i++){
        scanf("%d %d", &raio1, &raio2);
        printf("%d\n", raio1 + raio2);
    }

    return 0;
}