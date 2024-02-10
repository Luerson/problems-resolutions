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

const int MAX = 1'000'000;

// estruturas de dados do problema
vector<vector<int>> adj;

//variáveis do problema
int n, m;
bool targetFound;

vector<int> resp;
vector<int> visited;
vector<int> parent;
vector<int> deep;

vector<tuple<int, int, int>> edg; // {peso,[x,y]}
tuple<int, int, int> lowestEdge;

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        deep[i] = 1;
    }
}

int find_set(int v) {
   if (v == parent[v])
       return v;
   return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
   a = find_set(a);
   b = find_set(b);
   if (a != b) {
       if (deep[a] < deep[b])
           swap(a, b);
       parent[b] = a;
       deep[a] += deep[b];
   }
}

pair<ll, vector<tuple<int, int, int>>> kruskal(int n) {
	make_set(n);
	sort(edg.rbegin(), edg.rend());
	
	ll cost = 0;
	vector<tuple<int, int, int>> mst;
	for (auto [w,x,y] : edg) if (find_set(x) != find_set(y)) {
		mst.emplace_back(w, x, y);
		cost += w;
		union_sets(x,y);
	} else {
        get<0>(lowestEdge) = x;
        get<1>(lowestEdge) = y;
        get<2>(lowestEdge) = w;
    }
	return {cost, mst};
}

void dfs(int v, int target, int father) {
    resp.push_back(v);
    visited[v] = 1;

    for (int a: adj[v]) {
        if (a == target && !targetFound && a != father) {
            cout << get<2>(lowestEdge) << " " << resp.size() << endl;
            for (int i = 0; i < resp.size(); i++) {
                cout << resp[i] << " ";
            }
            cout << endl;

            targetFound = true;
        }

        if (!targetFound && !visited[a]) {
            dfs(a, target, v);
        }
    }

    resp.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        adj.clear();
        parent.clear();
        deep.clear();
        edg.clear();
        visited.clear();
        resp.clear();

        targetFound = false;

        adj.resize(n+1);
        parent.resize(n+1);
        deep.resize(n+1);
        visited.resize(n+1);

        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;

            adj[x].push_back(y);
            adj[y].push_back(x);

            edg.push_back(make_tuple(w, x, y));
        }

        kruskal(n+1);

        visited[get<0>(lowestEdge)] = 1;
        resp.push_back(get<0>(lowestEdge));
        dfs(get<1>(lowestEdge), get<0>(lowestEdge), get<0>(lowestEdge));
    }
    return 0;
}