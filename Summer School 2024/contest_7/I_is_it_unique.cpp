#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj; // adjacency list of graph
vector<int> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(int n) {
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    int n, k;
    vector<int> result;
    cin >> n >> k;
    
    adj.resize(n+1);
    visited.resize(n+1);
    result.resize(n);
    
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        
        adj[x].push_back(y);
    }
    
    topological_sort(n);
    
    int unique = 1;
    
    for (int i = 0; i < ans.size()-1; i++) {
        int found = 0;
        for (int j = 0; j < adj[ans[i]].size(); j++) {
            if (adj[ans[i]][j] == ans[i + 1]) {
                found = 1;
            }
        }
        
        if (!found) {
            unique = 0;
            break;
        }
    }
    
    int contador = 1;
    
    for (int i = 0; i < n; i++) {
        result[ans[i] - 1] = contador;
        contador++;
    }
    
    if (unique == 1) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        
    } else {
        cout << "No" << endl;
    }

    return 0;
}