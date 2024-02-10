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


// Resumo de iteradoes
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k, k<n? i<n: i>n; k<n? i += 1: i -= 1)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)


//Declaração de estruturas de dados
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vvpii;


//valor comum em problemas com módulo
const int mod = 1'000'000'007;

const int MAX = 1'000'000;

bool visited[MAX];

ll BIT[MAX + 1];

vector<pair<int, vector<pair<int, int>>>> queries;

vector<vector<int>> arestas;

vector<ll> resp;

void update(int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAX + 1; x += x&-x)
          BIT[x] += delta;
}


ll query(int x)//returns the sum of first x elements in given array a[]
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

void dfs(int v) {

    for (int i = 0; i < queries[v].second.size(); i++) {
        update(queries[v].second[i].first, queries[v].second[i].second);
    }

    for (int u : arestas[v]) {
        dfs(u);
    }

    resp[v] = query(MAX) - query(queries[v].first);

    for (int i = 0; i < queries[v].second.size(); i++) {
        update(queries[v].second[i].first, -(queries[v].second[i].second));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        queries.clear();
        arestas.clear();
        resp.clear();
        memset(visited, false, sizeof visited);

        queries.resize(2);
        arestas.resize(2);
        resp.resize(2);
        int currentTime = 2;
        int newVertex = 2;

        queries[1].first = 1;

        for (int i = 0; i < q; i++) {
            int tipo;
            cin >> tipo;

            if (tipo == 1) {
                int vertex;
                cin >> vertex;
                arestas[vertex].push_back(newVertex);

                newVertex++;

                arestas.resize(newVertex);
                queries.resize(newVertex);
                resp.resize(newVertex);
                queries[newVertex-1].first = currentTime;
            } else {
                int vertex, value;
                cin >> vertex >> value;

                queries[vertex].second.push_back(make_pair(currentTime, value));
            }

            currentTime++;
        }

        dfs(1);

        for (int i = 1; i < resp.size(); i++) {
            cout << resp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
