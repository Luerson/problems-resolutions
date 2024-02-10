#include <bits/stdc++.h>
 
using namespace std;
 
// Vetor para armazenar os valores já visitados
int visitados[2'000'000];
 
// Armazena o valor de N fornecido pela questão
int N;
 
// Vetor que armazena todos os valores fornecidos pelo problema
vector<int> sequencia;
 
// Variável para armazenar o total de partições necessárias
int totalDeParticoes = 0;
 
// Variável para armazenar a resposta final (quantidade de cortes)
int resp = 0;
 
// Variável temporária para acompanhar a quantidade máxima de partições
int temp = 1;
 
int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> N;
    memset(visitados, false, sizeof visitados); //todos os valores de 'visitados' iniciam como false
 
    // Preenchendo o vetor 'sequencia' com os valores fornecidos
    for (int i = 0; i < N; i++) {
        int valor;
        cin >> valor;
        sequencia.push_back(valor);
    }
 
    //Calculando a quantidade de partições distintas na sequencia
    for (int i = 0; i < N; i++) {
        if (sequencia[i] == 1 || visitados[sequencia[i] - 1] == false) {
            totalDeParticoes++;
        }
 
        visitados[sequencia[i]] = true;
    }
 
    // Calculando a quantidade de cortes necessários para cobrir todas as partições
    while (temp < totalDeParticoes) {
        resp++;
        temp *= 2;
    }
 
    cout << resp << endl;
 
    return 0;
}