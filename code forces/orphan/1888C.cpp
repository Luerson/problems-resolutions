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
        int n;
        ll total = 0;
        cin >> n;

        int valores[n];
        map<int, int> lastOccur;
        map<int, int> firstOccur;


        for (int i = 0; i < n; i++) {
            int valor;

            cin >> valor;

            valores[i] = valor;
        }

        for (int i = 0; i < n; i++) {
            lastOccur[valores[i]] = i;
        }

        for (int i = n-1; i >= 0; i--) {
            firstOccur[valores[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (firstOccur[valores[i]] == i) {
                total += lastOccur.size();
            }

            if (lastOccur[valores[i]] == i) {
                lastOccur.erase(valores[i]);
            }
        }

        cout << total << endl;
    }

    return 0;
}