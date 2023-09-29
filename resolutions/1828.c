#include <stdio.h>
#include <string.h>
#define REGRAS 10
#define MAX_CARACT 20

int main(){
    int t, i, j;
    char sheldon[MAX_CARACT], raj[MAX_CARACT];

    scanf("%d", &t);

    for(i = 0; i < t; i++){
        int empate;

        scanf("%s %s", sheldon, raj);

        empate = !strcmp(sheldon, raj);

        if(empate){
            printf("Caso #%d: De novo!\n", i+1);

        }else{
            int sheldon_vence;
            char *respostas;
            char regras[REGRAS][MAX_CARACT] = {"tesoura papel",
            "papel pedra", "pedra lagarto", "lagarto Spock",
            "Spock tesoura", "tesoura lagarto", "lagarto papel",
            "papel Spock", "Spock pedra", "pedra tesoura"};

            respostas = strcat(sheldon, " ");
            respostas = strcat(respostas, raj);

            sheldon_vence = 0;

            for(j = 0; j < REGRAS; j++){
                if(strcmp(respostas, &regras[j]) == 0){
                    sheldon_vence = 1;
                    break;
                }
            }
            
            if(sheldon_vence){
                printf("Caso #%d: Bazinga!\n", i+1);
            }else{
                printf("Caso #%d: Raj trapaceou!\n", i+1);
            }
        }
    }


    return 0;
}