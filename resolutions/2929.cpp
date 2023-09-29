#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    stack<int> presentes;
    queue<string> respostas;

    cin >> n;

    while (n--) {
        string operacao;
        int valor;

        cin >> operacao;

        if (operacao == "PUSH") {
            cin >> valor;
            if (presentes.empty())
                presentes.push(valor);
            else
                presentes.push(min(valor, presentes.top()));
        } else if (presentes.empty()) {
            //cout << "EMPTY" << endl;
            respostas.push("EMPTY");
        } else if (operacao == "POP"){
            presentes.pop();
        } else {
            //cout << presentes.top() << endl;
            respostas.push(to_string(presentes.top()));
        }
    }

    for (int i = 0; !respostas.empty(); i++) {
        cout << respostas.front() << endl;
        respostas.pop();
    }

    return 0;
}