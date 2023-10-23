#include <stdio.h>

int main(){
    int nCompetidores;

    while(scanf("%d", &nCompetidores) != EOF){
        int larg[nCompetidores], cheg[nCompetidores];
        int i, j, aux, contador = 0;

        for(i = 0; i < nCompetidores; i++){
            scanf("%d", &larg[i]);
        }

        for(i = 0; i < nCompetidores; i++){
            scanf("%d", &cheg[i]);
        }

        for(i = 0; i < nCompetidores; i++){
            if(larg[i] != cheg[i]){
                for(j = i; j < nCompetidores; j++){
                    if(larg[i] == cheg[j]){
                        while(j != i){
                            aux = cheg[j];
                            cheg[j] = cheg[j-1];
                            cheg[j-1] = cheg[j];
                            contador++;
                            j--;
                        }
                    }
                }
            }
        } 
        
        printf("%d\n", contador); 
    }

    return 0;
}