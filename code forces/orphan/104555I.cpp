#include <bits/stdc++.h>
using namespace std;


//Declarações de variáveis
#define endl '\n'
#define ll long long


//Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;


//Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))


//valor comum em problemas com módulo
const int mod = 1'000'000'007;
const int MAX = 100'000;

int N;

ll dpPar[MAX];
ll dpImpar[MAX];

int zerosEUns[MAX];

void solve(int index) {
    int impar = zerosEUns[index] == 1;

    if (index == N-1) {
        dpImpar[index] = impar == 1;
        dpPar[index] = impar == 0;
        return;
    }

    solve(index + 1);

    if (impar) {
        dpImpar[index] = 1 + dpPar[index + 1];
        dpPar[index] = dpImpar[index + 1];
        return;
    }

    dpImpar[index] = dpImpar[index + 1];
    dpPar[index] = 1 + dpPar[index + 1];
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(dpImpar, 0, sizeof dpImpar);
    memset(dpPar, 0, sizeof dpPar);

    for (int i = 0; i < N; i++) {
        cin >> zerosEUns[i];
    }

    solve(0);

    ll resp = 0;

    for (int i = 0; i < N; i++) {
        resp += dpImpar[i];
    }

    cout << resp << endl;

    return 0;
}
