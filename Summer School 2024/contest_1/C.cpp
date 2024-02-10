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

// Kosaraju
//
// O(n + m)

int n, m;
vector<vector<int>> g;
vector<vector<int>> gi; // grafo invertido
vector<int> vis;
stack<int> S;
vector<int> comp; // componente conexo de cada vertice

pair<int, int> noConect;

void dfs(int k) {
   vis[k] = 1;
   for (int i = 0; i < (int) g[k].size(); i++)
       if (!vis[g[k][i]]) dfs(g[k][i]);


   S.push(k);
}

void scc(int k, int c) {
   vis[k] = 1;
   comp[k] = c;
   for (int i = 0; i < (int) gi[k].size(); i++) {
        if (vis[gi[k][i]] && comp[k] != comp[gi[k][i]]) {
            noConect.first = k + 1;
            noConect.second = gi[k][i] + 1;
        }
        if (!vis[gi[k][i]]) scc(gi[k][i], c);
   }
}

void kosaraju() {
   for (int i = 0; i < n; i++) vis[i] = 0;
   for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);


   for (int i = 0; i < n; i++) vis[i] = 0;
   while (S.size()) {
       int u = S.top();
       S.pop();
       if (!vis[u]) scc(u, u);
   }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    g.resize(n);
    gi.resize(n);
    vis.resize(n);
    comp.resize(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        g[x-1].push_back(y-1);
        gi[y-1].push_back(x-1);
    }

    kosaraju();
    bool connected = true;

    for (int i = 1; i < n; i++) {
        if (comp[i] != comp[i-1]) {
            connected = false;
            if (noConect.first == 0 && noConect.second == 0) {
                noConect.first = i+1;
                noConect.second = i;
            }
            break;
        }
    }

    if (connected) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        cout << noConect.first <<  " " << noConect.second << endl;
    }
    
    return 0;
}
