#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, sum = 0;
        priority_queue<int, vector<int>, greater<int>> valores;

        cin >> n;

        for (int i = 0; i < n; i++) {
            int valor;
            cin >> valor;

            valores.push(valor);
        }

        while (valores.size() > 1) {
            int soma = 0;
            soma += valores.top();
            valores.pop();
            soma += valores.top();
            valores.pop();

            sum += soma;

            valores.push(soma);
        }

        cout << sum << endl;
    }

    return 0;
}