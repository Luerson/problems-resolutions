#include <stdio.h>
#include <string.h>

int main(){
    char genoma_D[101], genes_requeridos[101];
    char *resistente;

    while(scanf("%s %s", genoma_D, genes_requeridos) != EOF){
        resistente = strstr(genoma_D, genes_requeridos);

        if(resistente){
            printf("Resistente\n");
        }else{
            printf("Nao resistente\n");
        }
    }

    return 0;
}