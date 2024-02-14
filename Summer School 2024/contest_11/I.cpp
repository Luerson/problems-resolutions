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

const int block_size = 200;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int n, m, l;

vector<vector<int>> adj;
vector<Query> queries;
vector<int> dists;
vector<int> specials;
vector<int> visited;

queue<pair<int, int>> nodes;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    int dist = 0;

    if (is_ancestor(u, v))
        return dist;
    if (v == u)
        return dist;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            dist += (1 << i);
            u = up[u][i];
        }
    }
    return dist + 1;
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
}

void bfs_dist(pair<int, int> vertex) {
    int node = vertex.first;
    int dist = vertex.second;

    nodes.pop();

    visited[node] = 1;
    dists[node] = dist;

    for (auto a : adj[node]) {
        if (!visited[a]) {
            nodes.push(make_pair(a, dist+1));
        }
    }

    while(!nodes.empty() && visited[nodes.front().first]) nodes.pop();
    if (!nodes.empty()) {
        bfs_dist(nodes.front());
    }
}

void bfs(vector<int> specials) {
    for (int i = 0; i < specials.size(); i++) {
        nodes.push(make_pair(specials[i], 0));
    }

    bfs_dist(nodes.front());
}

void find_closer() {
    specials.push_back(1);

    for (int i = 0; i < m/block_size + 1; i++) {
        dists.clear();
        visited.clear();
        dists.resize(n+1, INT32_MAX);
        visited.resize(n+1);

        bfs(specials);

        for (int j = 0; j < block_size && block_size*i + j < m; j++) {
            int type = queries[block_size*i+j].l;
            int node = queries[block_size*i+j].r;

            if (type == 1) {
                specials.push_back(node);
            } else {
                int bestDist = dists[node];

                for (int k = 0; k < j; k++) {
                    int typeK = queries[block_size*i+k].l;
                    int nodeK = queries[block_size*i+k].r;

                    if (typeK == 1) {
                        bestDist = min(bestDist, lca(nodeK, node) + lca(node, nodeK));
                    }
                }

                cout << bestDist << endl;
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    adj.clear();
    adj.resize(n+1);
    queries.clear();
    queries.resize(m);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    preprocess(1);

    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r;
    }

    find_closer();
}

int main() {
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   ////////////////////////

    solve();
   return 0;
}
