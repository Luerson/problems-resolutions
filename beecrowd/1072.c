#include <stdio.h>

int main(){
    int nValores, valorX;
    int out, in;

    in = out = 0;
    
    scanf("%d", &nValores);

    while(nValores--){
        scanf("%d", &valorX);
        
        if(valorX >= 10 && valorX <= 20){
            in++;
        }else{
            out++;
        }
    }

    printf("%d in\n%d out\n", in, out);

    return 0;
}