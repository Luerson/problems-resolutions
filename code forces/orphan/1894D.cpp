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
vector<int> b;

//variáveis do problema
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        valores.clear();
        b.clear();

        for (int i = 0; i < n; i++) {
            int valor;

            cin >> valor;

            valores.push_back(valor);
        }

        for (int i = 0; i < m; i++) {
            int valor;
            cin >> valor;
            b.push_back(valor);
        }

        sort(b.rbegin(), b.rend());

        int j = 0;
        for (int i = 0; i < n; i++) {
            for (; j < m; j++) {
                if (b[j] < valores[i]) break;
                cout << b[j] << " ";
            }
            cout << valores[i] << " ";
        }
        while (j < m)  {
            cout << b[j] << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}