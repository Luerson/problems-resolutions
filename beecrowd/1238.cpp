/*
Implemente um programa denominado combinador, que recebe duas strings e deve combiná-las, alternando as letras
de cada string, começando com a primeira letra da primeira string, seguido pela primeira letra da segunda
string, em seguida pela segunda letra da primeira string, e assim sucessivamente. As letras restantes da cadeia
mais longa devem ser adicionadas ao fim da string resultante e retornada.

Entrada
A entrada contém vários casos de teste. A primeira linha contém um inteiro N que indica a quantidade de casos
de teste que vem a seguir. Cada caso de teste é composto por uma linha que contém duas cadeias de caracteres,
cada cadeia de caracteres contém entre 1 e 50 caracteres inclusive.

Saída
Combine as duas cadeias de caracteres da entrada como mostrado no exemplo abaixo e exiba a cadeia resultante.
*/

#include <iostream>
#include <string>

using namespace std;

void InserirApagar(string&, string&);
 
int main() {
 
    int n;
    cin >> n;
    
    while (n--) {
        string palavra1, palavra2, mix;
        
        cin >> palavra1 >> palavra2;

        while (not palavra1.empty() and not palavra2.empty())
        {
            InserirApagar(mix, palavra1);
            InserirApagar(mix, palavra2);
        }
        
        while (not palavra1.empty())
        {
            InserirApagar(mix, palavra1);
        }

        while (not palavra2.empty())
        {
            InserirApagar(mix, palavra2);
        }
        
        cout << mix << endl;
    }

    return 0;
}

void InserirApagar(string &mix, string &palavra) {
    mix.insert(mix.length(), 1, palavra[0]);
    palavra.erase(0, 1);
}