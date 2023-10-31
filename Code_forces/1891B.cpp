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


int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;


        long long valoresN[n];
        vector<int> valoresQ;
        vector<long long> respostas;


        for (int i = 0; i < n; i++) {
            long long valor;


            cin >> valor;


            valoresN[i] = valor;
        }

        for (int i = 0; i < q; i++) {
            int valor;

            cin >> valor;

            if (valoresQ.empty() || valor < valoresQ.back()) {
                valoresQ.push_back(valor);
            }
        }

        for (int i = 0; i < valoresQ.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (valoresN[j]%(1<<valoresQ[i]) == 0) {
                    valoresN[j] += (1<<(valoresQ[i] - 1));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << valoresN[i];
            if (i != n-1) {
                cout << " ";
            }
        }

        cout << endl;
    }
    return 0;
}
