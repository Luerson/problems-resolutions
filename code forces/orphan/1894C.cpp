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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int valores[n];

        for (int i = 0; i < n; i++) {
            int valor;


            cin >> valor;


            valores[i] = valor;
        }
        int cont = 0;

        for (int i = n-1; valores[i] <= n && cont < n && cont < k;) {
            if (valores[i] > n) break;
            cont++;

            i = i - valores[i];
            if (i < 0) i += n;
        }

        if (cont == n || cont == k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
