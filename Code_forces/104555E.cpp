#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

const int mod = 1'000'000'007;
const int MAX = 1'000'000;

ll pollen[MAX + 1];

ll n, k;

int somaDosFatores(int valor) {
    int soma = 0;
    while (valor != 0) {
        soma += valor%10;
        valor = valor/10;
    }

    return soma;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    memset(pollen, 0, sizeof pollen);

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        
        pollen[valor]++;
    }

    for (int i = MAX; i >= 0; i--) {
        int soma = somaDosFatores(i);
        int novoValor = i - soma;

        k -= pollen[i];
        pollen[novoValor] += pollen[i];
        pollen[i] = 0;

        if (k <= 0) {
            cout << soma << endl;
            break;
        }
    }

    if (k > 0) {
        cout << 0 << endl;
    }
}
