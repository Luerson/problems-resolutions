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

int n, m;
vector<vector<int>> g;
stack<int> s;
vector<int> id, art;

int dfs_art(int i, int& t, int p = -1) {
   int lo = id[i] = t++;
   s.push(i);
   for (int j : g[i]) if (j != p) {
       if (id[j] == -1) {
           int val = dfs_art(j, t, i);
           lo = min(lo, val);


           if (val >= id[i]) {
               art[i]++;
               while (s.top() != j) s.pop();
               s.pop();
           }
           // if (val > id[i]) aresta i-j eh ponte
       }
       else lo = min(lo, id[j]);
   }
   if (p == -1 and art[i]) art[i]--;
   return lo;
}

void compute_art_points() {
   id = vector<int>(n, -1);
   art = vector<int>(n, 0);
   int t = 0;
   for (int i = 0; i < n; i++) if (id[i] == -1)
       dfs_art(i, t, -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int resp = 0;
    vector<int> pontos_art;

    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    compute_art_points();

    for (int i = 0; i < art.size(); i++) {
        if (art[i] >= 1) {
            resp++;
            pontos_art.push_back(i+1);
        }
    }

    cout << resp << endl;
    for (int i = 0; i < pontos_art.size(); i++) {
        cout << pontos_art[i] << " ";
    }
    cout << endl;
    
    return 0;
}
