#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;

    while (cin >> n) {
        priority_queue<int> fila;
        float hora = 7;
        float H, M, C;
        int contador = 0;

        for (int i = 0; i < n; i++) {
            cin >> H >> M >> C;

            while (hora < (H + M/60)) {
                hora += 0.5;
            }

            if (hora - (H + M/60) > C/60) {
                contador++;
            }
            hora += 0.5;
        }

        cout << contador << endl;
    }

    return 0;
}