#include <bits/stdc++.h>

using namespace std;

int lados[4];

void solve() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 && j != i; j++) {
            for (int k = 0; k < 4 && k != i && k != j; k++) {
                if (lados[i] < lados[j] + lados[k] && lados[j] < lados[k] + lados[i] && lados[k] < lados[i] + lados[j]) {
                    printf("S\n");
                    return;
                }
            }
        }
    }
    printf("N\n");
}

int main() {
    
    for (int i = 0; i < 4; i++) {
        cin >> lados[i];
    }

    solve();

    return 0;
}