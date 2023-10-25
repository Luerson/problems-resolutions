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

    multiset<int> inicios;
    multiset<int> finais;

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        char operation;
        cin >> operation >> l >> r;
        
        if (operation == '+') {
            inicios.insert(l);
            finais.insert(r);
        } else {
            auto it = inicios.find(l);
            inicios.erase(it);
            
            it = finais.find(r);
            finais.erase(it);
        }

        multiset<int>::iterator iteradorMenorFinal = finais.begin();
        multiset<int>::iterator iteradorMaiorInicio = inicios.end();

        if (inicios.empty()) {
            iteradorMaiorInicio = inicios.begin();
        } else {
            iteradorMaiorInicio--;
        }

        if (inicios.empty() || ((*iteradorMenorFinal) >= (*iteradorMaiorInicio))) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
