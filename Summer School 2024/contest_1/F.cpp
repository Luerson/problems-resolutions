#include <bits/stdc++.h>

#define MAX 200001

using namespace std;

vector<vector<int>> adj; // graph represented as an adjacency list

bool visited[MAX];
int cats[MAX];

int resp = 0;

int n, m;

void dfs(int v, int totalCats, int maxCats) {
    
    visited[v] = true;

    if (cats[v] == 1) {
        totalCats++;
    } else {
        totalCats = 0;
    }
    
    if (maxCats < totalCats) {
        maxCats = totalCats;
    }

    if (adj[v].size() == 1 && v != 1 && maxCats <= m) {
        resp++;
    }

    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, totalCats, maxCats);
    }
}

int main () {
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;

        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, 0);

    cout << resp << endl;

    return 0;
}