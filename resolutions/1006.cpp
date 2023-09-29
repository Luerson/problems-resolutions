/*
Leia 3 valores, no caso, variáveis A, B e C, que são as três notas de um aluno. A seguir, calcule
a média do aluno, sabendo que a nota A tem peso 2, a nota B tem peso 3 e a nota C tem peso 5.
Considere que cada nota pode ir de 0 até 10.0, sempre com uma casa decimal.

Entrada
O arquivo de entrada contém 3 valores com uma casa decimal, de dupla precisão (double).

Saída
Imprima a mensagem "MEDIA" e a média do aluno conforme exemplo abaixo, com 1 dígito após o ponto decimal
e com um espaço em branco antes e depois da igualdade. Assim como todos os problemas, não esqueça de imprimir
o fim de linha após o resultado, caso contrário, você receberá "Presentation Error".
*/
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
    float a, b, c, media;
    cin >> a >> b >> c;
    
    media = (2*a + 3*b + 5*c)/10;
    
    cout << fixed << setprecision(1) << media << endl;
 
    return 0;
}