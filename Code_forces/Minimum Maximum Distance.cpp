#include <bits/stdc++.h>
using namespace std;

//Declarações de variáveis
#define endl '\n'
#define ll long long
#define ld long double
#define llu unsigned long long int

//Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;

//Resumo de métodos das estruturas de dados
#define pb push_back
#define mp make_pair

//Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define MsetZ(x) memset(x, 0, sizeof x)
#define MsetN(x) memset(x, -1, sizeof x)
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

vector<vector<int>> arestas;
vector<int> distancia;
vector<int> especial;
vector<int> visitados;
vector<int> listaEspeciais;
int novoEspecial;

int n; // number of vertices

void dfs(int v, int dist, int l) {
    if (visitados[v]) {
        return;
    }

    visitados[v] = 1;

    if (especial[v] == 1 && dist >= distancia[novoEspecial]) {
        novoEspecial = v;
    }

    if (dist >= distancia[v]) {
        distancia[v] = dist;
    }

    for (int i = 0; i < arestas[v].size(); i++) {
        dfs(arestas[v][i], dist + 1, l);
    }

    visitados[v] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        arestas.clear();
        arestas.resize(n + 1);

        distancia.clear();
        distancia.resize(n + 1);

        especial.clear();
        especial.resize(n + 1);

        visitados.clear();
        visitados.resize(n + 1);

        for (int i = 0; i <= n; i++) {
          distancia[i] = especial[i] = visitados[i] = 0;
        }

        for (int i = 0; i < k; i++) {
            int marcado;
            cin >> marcado;

            especial[marcado] = 1;
            novoEspecial = marcado;
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            arestas[u].push_back(v);
            arestas[v].push_back(u);
        }

        for (int i = 0; i < 3; i++) {
            dfs(novoEspecial, 0, i);
        }

        int resposta = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (distancia[i] < resposta) {
                resposta = distancia[i];
            }
        }

        cout << resposta << endl;
    }

    return 0;
}