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
    int t;
    cin >> t;
    while (t--) {
        string codigo;
        int resp = 0;
        cin >> codigo;

        for (int i = 0; i < 3; i++) {
            if (codigo[i] == '0' && codigo[i + 1] != 0 && codigo[i+1] != codigo[i]) {
                resp += abs(codigo[i + 1] - (10 + '0'));
            } else if (codigo[i + 1] == '0' && codigo[i] != 0 && codigo[i+1] != codigo[i]){
                resp += abs((10 + '0') - codigo[i]);
            } else {
                resp += abs(codigo[i+1] - codigo[i]);
            }
        }

        resp += 4;
        if (codigo[0] == '0') {
            resp += 9;
        } else {
            resp += codigo[0] - '1';
        }

        cout << resp << endl;
    }

    return 0;
}
