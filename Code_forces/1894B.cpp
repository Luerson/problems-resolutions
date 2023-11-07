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
const int MAX = 100;

vector<pair<int, int>> indices;
int resp[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, cont = 0;
        cin >> n;

        memset(resp, -1, sizeof resp);
        int valores[n];
        indices.clear();

        for (int i = 0; i < n; i++) {
            int valor;

            cin >> valor;

            valores[i] = valor;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (valores[i] == valores[j] && i != j) {
                    if (indices.size() != 0 && valores[indices[0].first] == valores[i]) {
                        break;
                    }
                    cont++;
                    indices.push_back(make_pair(i, j));
                }
                if (cont >= 2) break;
            }
            if (cont >= 2) break;
        }
        
        if (cont < 2) {
            cout << -1 << endl;
        } else {
            int valor = 1;

            if (resp[indices[0].first] == -1) {
                resp[indices[0].first] = valor;
                valor++;
            }

            if (resp[indices[0].second] == -1) {
                resp[indices[0].second] = valor;
                valor++;
            }

            if (resp[indices[1].first] == -1) {
                resp[indices[1].first] = valor;
                valor++;
                valor%=3;
            }

            if (resp[indices[1].second] == -1) {
                resp[indices[1].second] = valor;
            }

            for (int i = 0; i < n; i++) {
                cout << (resp[i] == -1? 1:resp[i]) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
