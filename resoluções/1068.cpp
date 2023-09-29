#include<bits/stdc++.h>

using namespace std;

int main() {
    string sequencia;

    while (cin >> sequencia) {
        stack<int> parenteses;
        int correto = 1;

        for (int i = 0; i < sequencia.length(); i++) {
            if (sequencia[i] == '(') {
                parenteses.push(sequencia[i]);
            }

            if (sequencia[i] == ')' && parenteses.size() == 0) {
                correto = 0;
                break;
            }

            if (sequencia[i] == ')') {
                parenteses.pop();
            }
        }

        if (parenteses.size() != 0 || !correto) {
            cout << "incorrect" << endl;
        } else {
            cout << "correct" << endl;
        }
    }
    return 0;
}