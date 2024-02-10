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

// Bellman-Ford
//
// Calcula a menor distancia
// entre a e todos os vertices e
// detecta ciclo negativo
// Retorna 1 se ha ciclo negativo
// Nao precisa representar o grafo,
// soh armazenar as arestas
//
// O(nm)

const int MAX = 500'000;
const ll LINF = LONG_LONG_MAX;

vector<int> used(MAX);
vector<vector<pair<ll, ll>>> adj;
typedef pair<ll, ll> pqType;
priority_queue<pqType, vector<pqType>, greater<pqType>> pq;

int n;

ll dijkstra() {

    pq.push({0, 1});
    while(!pq.empty())
    {
        ll currCost = pq.top().first;
        ll v = pq.top().second;
        pq.pop();

        if (v == n)
        {
            return currCost;
        }
        else if (used[v])
        {
            continue;
        }
        used[v] = true;

        for (pll& it : adj[v])
        {
            ll u = it.first;
            ll cost = it.second;

            if (!used[u])
            {
                pq.push({currCost + cost, u});
            }
        }
    }

    return -1;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    cin >> n;
    adj.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b, x;
        cin >> a >> b >> x;

        adj[i].push_back(make_pair(i+1, a));
        adj[i].push_back(make_pair(x, b));
    }    

    cout << dijkstra() << endl;

   return 0;
}
