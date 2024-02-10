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
const int MAX = 10'000;
int D, C, R, cont;

int exaustivo[MAX];
int revigorantes[MAX];

int solve() {
    cont = 0;

    for (int i = 0; i < R; i++) {
        D += revigorantes[i];
        cont++;
    }

    for (int i = 0; i < C; i++) {
        D -= exaustivo[i];
        if (D >= 0) {
            cont++;
        } else {
            return cont;
        }
    }

    return cont;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> D >> C >> R;

    for (int i = 0; i < C; i++) {
        cin >> exaustivo[i];
    }

    for (int i = 0; i < R; i++) {
        cin >> revigorantes[i];
    }

    cont = solve();

    cout << cont << endl;

    return 0;
}