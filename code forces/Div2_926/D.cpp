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

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 37;
const ll PRIME_HASH2 = 31;

using namespace std;

vector<int> visited;
vector<vector<int>> adj;
vector<tuple<ll, ll, ll>> dp;

void dfs_pos(int v, int fa) {
    visited[v] = 1;

    get<0>(dp[v]) = 1;
    get<1>(dp[v]) = 1;
    get<2>(dp[v]) = 0;

    for (auto a: adj[v]) {
        if (!visited[a]) {
            dfs_pos(a, fa);
            get<1>(dp[v]) *= (get<0>(dp[a]) + get<1>(dp[a]))%MOD_FFT;
            get<1>(dp[v]) %= MOD_FFT;
            get<2>(dp[v]) += (get<1>(dp[a]) + get<2>(dp[a]))%MOD_FFT;
            get<2>(dp[v]) %= MOD_FFT;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    adj.clear();
    dp.clear();
    visited.clear();

    adj.resize(n);
    dp.resize(n);
    visited.resize(n);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs_pos(0, 0);

    cout << (get<0>(dp[0]) + get<1>(dp[0]) + get<2>(dp[0]))%MOD_FFT << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}