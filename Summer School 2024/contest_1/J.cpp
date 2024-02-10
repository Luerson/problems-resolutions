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
vector<int> visitados;

//variáveis do problema
int n;

vector<vector<int>> adj;

vector<int> backEdge(int v, int father) {
    visitados[v] = 1;

    vector<int> result;

    for (auto a : adj[v]) {
        if (visitados[a] && a != father) {
            result.push_back(a);
            result.push_back(v);

            return result;
        }

        if (!visitados[a] && a != father) {
            result = backEdge(a, v);

            if (result.size() != 0) {
                if (result[0] != result[result.size() - 1]) {
                    result.push_back(v);
                }
                return result;
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> resp;

    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visitados.resize(n+1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!visitados[i]) {
            resp = backEdge(i, 0);
        }

        if (resp.size() != 0) {
            reverse(resp.begin(), resp.end());
            
            cout << resp.size() << endl;

            for (int j = 0; j < resp.size(); j++) {
                cout << resp[j] << " ";
            }
            cout << endl;
            break;
        }
    }

    if (resp.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}