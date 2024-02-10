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
const int MAX = 300'000;

vector<vector<int>> adj; // graph represented as an adjacency list
vector<vector<int>> inverted; // graph represented as an adjacency list
int n, k; // number of vertices

bool visited[MAX+1];
priority_queue<pair<int, pair<int, int>>> leafs;
priority_queue<int> results;

void dfs(int v, int deep) {
    visited[v] = true;

    if (adj[v].size() == 0) {
        leafs.push(make_pair(deep, make_pair(1, v)));
    }
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, deep+1);
    }
}

void dfs2(int v) {

    if (inverted[v].size() != 0 && !visited[inverted[v][0]]) {
        pair<int, pair<int, int>> newLeaf;
        newLeaf = leafs.top();

        // debug2(v, inverted[v][0])

        leafs.pop();

        leafs.push(make_pair(newLeaf.first-1, make_pair(newLeaf.second.first+1, inverted[v][0])));
        visited[inverted[v][0]] = 1;
    } else if (inverted[v].size() == 0 || visited[inverted[v][0]]) {
        results.push(leafs.top().second.first);
        leafs.pop();
    }

    if (leafs.size() > 0) {
        dfs2(leafs.top().second.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    adj.clear();
    inverted.clear();

    adj.resize(n+1);
    inverted.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int valor;

        cin >> valor;

        adj[valor].push_back(i+2);
        inverted[i+2].push_back(valor);
    }

    dfs(1, 0);

    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }

    // visited[1] = 1;
    dfs2(leafs.top().second.second);

    int soma = 0;

    for (int i = 0; i < k; i++) {
        if (results.size() == 0) {
            break;
        }

        soma += results.top();
        results.pop();
    }
    cout << soma << endl;

    return 0;
}
