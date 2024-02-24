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

vector<vector<int>> adj;
map<pair<int, int>, int> edges;
set<int> bitmasks;
vector<int> visited;

int resp;
int t;

int dfs_mark(int v, int target, int power) {
    visited[v] = 1;

    if (v == target) return 1;

    for (auto a : adj[v]) {
        if (!visited[a] && dfs_mark(a, target, power)) {
            edges[make_pair(v, a)] += (1<<power);
            edges[make_pair(a, v)] += (1<<power);
            return 1;
        }
    }

    return 0;
}

void edges_count() {
    for (auto edge : edges) {
        edges.erase(make_pair(edge.first.second, edge.first.first));
        int path = edge.second;
        int newPath = path;

        vector<int> toErase;

        debug2(edge.first.first, edge.first.second);

        for (auto bitmask : bitmasks) {
            if (bitmask == (path & bitmask)) {
                resp--;

                toErase.push_back(bitmask);
            } else {
                path -= (path & bitmask);
            }
        }

        for (int i = 0; i < toErase.size(); i++) {
            bitmasks.erase(toErase[i]);
        }

        if (path != 0) {
            debug2(path, resp);
            bitmasks.insert(newPath);
            resp++;
        }
    }
}

void solve(int test) {
    int n, k;
    cin >> n;

    resp = 0;

    adj.clear();
    adj.resize(n);

    edges.clear();

    bitmasks.clear();

    if (test == 63) {
        cout << n << endl;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        if (test == 63) {
            cout << a << " " << b << endl;
        }

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    cin >> k;

    if (test == 63) {
        cout << k << endl;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        if (test == 63) {
            cout << a << " " << b << endl;
        }

        visited.clear();
        visited.resize(n);

        dfs_mark(a-1, b-1, i);
    }

    edges_count();

    if (t < 63) {
        cout << resp << endl;
    } else if (test == 63) {
        cout << resp << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}