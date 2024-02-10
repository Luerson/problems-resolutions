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

// estruturas de dados do problema
vector<int> valores;
vector<int> ultimoDif;

//variáveis do problema
int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        valores.clear();
        valores.resize(n);
        ultimoDif.clear();
        ultimoDif.resize(n);

        int last = -1;

        for (int i = 0; i < n; i++) {
            cin >> valores[i];
        }

        ultimoDif[0] = -1;

        for (int i = 1; i < n; i++) {
            if (valores[i] != valores[i-1]) {
                last = i-1;
            }

            ultimoDif[i] = last;
        }

        cin >> q;

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            if (ultimoDif[r] < l) {
                cout << -1 << " " << -1 << endl;
            } else {
                cout << r +1<< " " << ultimoDif[r]+1 << endl;
            }
        }
    }
    return 0;
}
