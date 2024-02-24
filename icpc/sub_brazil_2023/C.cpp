#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long double ld;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

const int MAX = 100010;

using namespace std;

vector<ll> tree(4*(MAX+1));

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 0;
    } else {
        int mid = (start + end)/2;

        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);
        tree[node] = max(tree[2*node], tree[2*node + 1]);
    }
}

void update (int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;

        if (start <= idx and idx <= mid) {
            update(2*node, start, mid, idx, val);
        } else {
            update(2*node + 1, mid+1, end, idx, val);
        }

        tree[node] = max(tree[2*node], tree[2*node + 1]);
    }
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start or end < l) {
        return 0;
    }

    if (l <= start and end <= r) {
        return tree[node];
    }

    int mid = (start + end)/2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node + 1, mid+1, end, l, r);
    return max(p1, p2);
}

//compressão de coordenadas
map<ll, ll> valorCoordenada; //a key é o valor original e value é a coordenada
map<ll, ll> coordenadaValor; // a key é a coordenada e value é o valor original

//Essa função preenche os valores das maps de conversão a partir do vetor original
void build(vector<ll> OgVetor, int n) {
    ll ind = 1;
    vector<ll> a = OgVetor;
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if (!valorCoordenada[a[i]]) {
            valorCoordenada[a[i]] = ind;
            coordenadaValor[ind] = a[i];
            ind++;
        }
    }

    return;
}

//Recebe o vetor com os valores originais e converte para suas coordenadas
void compress(vector<ll>& vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = valorCoordenada[vetor[i]];
    }
}

vector<vector<int>> adj;
vector<int> visited;
vector<ll> prices;
vector<ll> resps;

int n;

void dfs(int v) {
    visited[v] = 1;

    ll newVal = 1 + query(1, 0, MAX-1, 0, prices[v]-1);
    ll prevVal = query(1, 0, MAX-1, prices[v], prices[v]);
    update(1, 0, MAX-1, prices[v], newVal);

    resps[v] = query(1, 0, MAX-1, 0, MAX-1);

    //
    //debug2(v, query(1, 0, MAX, 0, prices[v]-1));
    //debug2(v, resps[v]);
    //for (int i = 0; i < 10; i++) {
    //    cout << tree[i] << " ";
    //}
    //cout << endl;

    for (auto a : adj[v]) {
        if (!visited[a]) {
            dfs(a);
        }
    }

    update(1, 0, MAX-1, prices[v], prevVal);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    adj.resize(n);
    resps.resize(n);
    visited.resize(n);
    prices.resize(n);

    build(1, 0, n);

    for (int i = 0; i < n-1; i++) {
        ll valor;
        cin >> valor;

        adj[i+1].push_back(valor-1);
        adj[valor-1].push_back(i+1);
    }

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    build(prices, n);
    compress(prices, n);

    dfs(0);

    for (int i = 1; i < resps.size(); i++) {
        cout << resps[i] << " ";
    }
    cout << endl;

    return 0;
}