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

const int MAX = 100; // Máximo de vértices do problema

int d[MAX + 1][MAX + 1]; // melhor distância entre os pares de vértices após execução do algoritmo
int retirar[MAX + 1][MAX + 1]; // melhor distância entre os pares de vértices após execução do algoritmo

// Recebe a matriz com os pesos originais das arestas e a quantidade de vértices no grafo
int floyd_warshall_A(int pesoOg[MAX + 1][MAX + 1], int n)
{
    // inicialmente, a distância de u->v será o peso da sua aresta (se existir)
    // caso não exista, então seu valor será infinito (um valor bem grande) ou 0 se u = v.
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = pesoOg[i][j];


    for (int k = 1; k <= n; k++) // vértice intermediário
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]); // recursão principal
                if (d[i][j] < pesoOg[i][j]) {
                    return 0;
                }
            }

    return 1;
}

int floyd_warshall_B(int pesoOg[MAX + 1][MAX + 1], int n)
{
    int redundante = 0;
    memset(retirar, 0, sizeof retirar);
    // inicialmente, a distância de u->v será o peso da sua aresta (se existir)
    // caso não exista, então seu valor será infinito (um valor bem grande) ou 0 se u = v.
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = pesoOg[i][j];


    for (int k = 1; k <= n; k++) // vértice intermediário
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (pesoOg[i][j] == d[i][k] + d[j][k] && retirar[i][j] == 0 && i != j && k != j && k != i) {
                    redundante++;
                    retirar[i][j] = 1;
                    retirar[j][i] = 1;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]); // recursão principal

            }

    return redundante;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pesoOg[MAX + 1][MAX + 1];

    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pesoOg[i][j];
            pesoOg[j][i] = pesoOg[i][j];
        }
    }

    int coerente = floyd_warshall_A(pesoOg, n);

    if (coerente) {
        cout << floyd_warshall_B(pesoOg, n) << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
