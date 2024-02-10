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

const int MAX = 200000;

priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>>> leafs;
vector<int> visited;
vector<int> connected;
vector<vector<int>> adjDir;
vector<vector<int>> adjInv;
vector<vector<int>> adj;

void dfs1(int v, int father, int deep) {
    
}

void solve() {
    int n;
    cin >> n;

    visited.clear();
    connected.clear();
    adjDir.clear();
    adjInv.clear();
    adj.clear();

    visited.resize(n+1);
    connected.resize(n+1);
    adjDir.resize(n+1);
    adjInv.resize(n+1);
    adj.resize(n);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs1(1, 1, 0);
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

   solve();

   return 0;
}
