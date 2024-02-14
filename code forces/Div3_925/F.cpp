#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;

vector<set<int>> adj;
vector<set<int>> invertAdj;
vector<int> grau;
queue<int> nodes;

int cont;

int ordenacao_topologica() {
   if (nodes.empty()) {
      return cont;
   }

   int node = nodes.front();
   nodes.pop();

   cont++;

   for (auto a : invertAdj[node]) {
      grau[a]--;
      if (grau[a] == 0) {
         nodes.push(a);
      }
   }

   return ordenacao_topologica();
}

void solve() {
   int t;
   cin >> t;

   while (t--) {
      int n, k;
      cin >> n >> k;

      cont = 0;

      adj.clear();
      invertAdj.clear();
      grau.clear();

      adj.resize(n);
      invertAdj.resize(n);
      grau.resize(n);

      for (int j = 0; j < k; j++) {
         vector<int> valores(n);

         for (int i = 0; i < n; i++) {
            cin >> valores[i];
            valores[i]--;
         }

         for (int i = 2; i < n ; i++) {
            adj[valores[i-1]].insert(valores[i]);
            invertAdj[valores[i]].insert(valores[i-1]);
         }
      }

      for (int i = 0; i < n; i++) {
         grau[i] = adj[i].size();
         if (grau[i] == 0) {
            nodes.push(i);
         }
      }

      if (ordenacao_topologica() == adj.size()) {
         cout << "YES" << endl;
      } else {
         cout << "NO" << endl;
      }
   }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

   solve();

   return 0;
}
