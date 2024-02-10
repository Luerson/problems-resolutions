#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    priority_queue<int> valores;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;

        valores.push(valor);
    }

    int sumImp = 0, sumP = 0;

    while (!valores.empty()) {
        sumImp += valores.top();
        valores.pop();

        if (!valores.empty()) {
            sumP += valores.top();
            valores.pop();
        }
    }

    cout << sumImp << " " << sumP << endl;

    return 0;
}