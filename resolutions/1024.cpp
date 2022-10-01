/*
Solicitaram para que você construisse um programa simples de criptografia. Este programa deve possibilitar enviar
mensagens codificadas sem que alguém consiga lê-las. O processo é muito simples. São feitas três passadas em todo 
o texto.

Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições
para a direita, segundo a tabela ASCII: letra 'a' deve virar letra 'd', letra 'y' deve virar caractere '|' e
assim sucessivamente. Na segunda passada, a linha deverá ser invertida. Na terceira e última passada, todo e
qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posição para a esquerda na
tabela ASCII. Neste caso, 'b' vira 'a' e 'a' vira '`'.

Por exemplo, se a entrada for “Texto #3”, o primeiro processamento sobre esta entrada deverá produzir “Wh{wr #3”.
O resultado do segundo processamento inverte os caracteres e produz “3# rw{hW”. Por último, com o deslocamento
dos caracteres da metade em diante, o resultado final deve ser “3# rvzgV”.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*104), 
indicando a quantidade de linhas que o problema deve tratar. As N linhas contém cada uma delas M (1 ≤ M ≤ 1*103) 
caracteres.

Saída
Para cada entrada, deve-se apresentar a mensagem criptografada.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

int main() {
    while (not cin.eof()) {
        int n;
        cin >> n; // ler número de linhas
        cin.ignore(); // eliminar '\n' remanescente

        for (int i = 0; i < n; i++) {
            string line;
            int lineLength;

            getline(cin, line);
            lineLength = line.length();


            // Mover maiúsculas e minúsculas 3 casas à direita na tabela ASCII
            for (int j = 0; j < lineLength; j++) {
                if (isupper(line[j]) or islower(line[j])) {
                    line[j] += 3;
                }
            }


            // reverter a string
            reverse(line.begin(), line.end());


            // a partir da metade, deloca 1 para esquerda na tabela ASCII
            for (int j = lineLength/2; j < lineLength; j++) {
                line[j] -= 1;
            }

            cout << line << endl;
        }
        break;
    }

    return 0;
}