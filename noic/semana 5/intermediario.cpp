#include <bits/stdc++.h>
#define dpUpdate dp[ultimoTestado][testeAtual][totalDePrototipos]

using namespace std;

int C, p, m, resp;

int dp[1100][1100][60];

int solve(int ultimoTestado, int testeAtual, int totalDePrototipos) {
    if (dpUpdate != -1) {
        return dp[ultimoTestado][testeAtual][totalDePrototipos];
    }

    if (ultimoTestado == testeAtual) {
        dpUpdate = 0;
        return dpUpdate;
    }

    if (totalDePrototipos == 0) {
        dpUpdate = 0;
        return dpUpdate;
    }

    if (testeAtual == m) {
        dpUpdate = 1;
        
    } 

    int casoQuebre = 0;
    int casoAguente = 0;

    casoQuebre = 1 + solve(testeAtual, ultimoTestado + 1, totalDePrototipos - 1);
    casoAguente = 1 + solve();
}

int solve() {
    int menorPiorCaso = INT_MAX;

    for (int i = 1; i <= m; i++) {
        menorPiorCaso = min(menorPiorCaso, solve(0, i, p));
    }

    return menorPiorCaso;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> C;

    for (int i = 0; i <= C; i++) {
        cin >> p >> m;

        resp = solve();

        cout << resp << endl;
    }

    return 0;
}