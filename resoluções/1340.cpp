#include <bits/stdc++.h>

//teste

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        queue<int> fila;
        stack<int> pilha;
        priority_queue<int, vector<int>, less<int>> filaDePrioridade;

        int ehFila = 1, ehPilha = 1, ehFP = 1;

        for (int i = 0; i < n; i++) {
            int operacao;
            int valor;

            cin >> operacao >> valor;

            if (operacao == 1) {
                fila.push(valor);
                pilha.push(valor);
                filaDePrioridade.push(valor);
            }

            if (operacao == 2) {
                ehFila = (fila.front() == valor)*ehFila;
                ehPilha = (pilha.top() == valor)*ehPilha;
                ehFP = (filaDePrioridade.top() == valor)*ehFP;

                fila.pop();
                pilha.pop();
                filaDePrioridade.pop();
            }
        }

        if (ehFila + ehPilha + ehFP > 1) {
            cout << "not sure" << endl;
        } else if (ehFila) {
            cout << "queue" << endl;
        } else if (ehPilha){
            cout << "stack" << endl;
        } else if(ehFP) {
            cout << "priority queue" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}