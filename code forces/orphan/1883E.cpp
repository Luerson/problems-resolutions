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
        long long n, last = 0;
        long long sum = 0;
        cin >> n;


        long valores[n];


        for (int i = 0; i < n; i++) {
            cin >> valores[i];
        }

        for (int i = 1; i < n; i++) {
            if (valores[i] < valores[i - 1]) {
                long long valor = valores[i];

                while (valor < valores[i-1]) {
                    valor *= 2;
                    last++;
                }
            } else if (valores[i] > valores[i-1]) {
                long long valor = valores[i - 1];
                while (last > 0 && valores[i] > valor) {
                    valor *= 2;
                    last--;
                }
                
                long long valor2 = valores[i];
                while(valor2 < valor) {
                    last++;
                    valor2 *= 2;
                }
            }
            sum += last;
        }

        cout << sum << endl;
    }
    return 0;
}
