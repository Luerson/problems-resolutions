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
        cin >> n;


        vector<long long> valores;


        for (int i = 0; i < n; i++) {
            int valor;

            cin >> valor;

            valores.push_back(valor);
        }

        sortall(valores);

        int i = 0;
        int j = valores.size() - 1;
        long long power = 0;
        long long contador = 0;

        for (; i < valores.size(); i++) {

            if (j >= 0 && power >= valores[j] && valores[j] != 0) {
                power -= valores[j];
                valores[j] = 0;
                j--;
                contador++;
            } else if (valores[i] != 0 && i != j){
                long long currentPower = power;
                long long currentValores = valores[i];

                contador += min(currentValores, valores[j] - currentPower);
                power += min(currentValores, valores[j] - currentPower);
                valores[i] -= min(currentValores, valores[j] - currentPower);

            } else if (valores[i] != 0 && i == j) {
                long long dif = (valores[i] - power + 1)/2;

                power += dif;
                contador += dif;
                valores[i] -= dif;
            }

            if (valores[i] != 0) i--;
        }

        cout << contador << endl;
    }
    return 0;
}
