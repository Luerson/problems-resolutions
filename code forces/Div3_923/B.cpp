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

//valor comum em problemas com módulo
const int mod = 1'000'000'007;

const int MAX = 1'000'000;

// estruturas de dados do problema
vector<int> valores;

vector<set<int>> letras;

//variáveis do problema
int n;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    valores.resize(200001);
    
    while (t--) {
        cin >> n;
        valores.clear();
        valores.resize(n);

        letras.clear();
        letras.resize(n);

        string s;

        for (int i = 0; i < n; i++) {
            cin >> valores[i];
        }

        for (int i = 0; i < 26; i++) {
            letras[0].insert(i);
        }

        for (int i = 0; i < n; i++) {
            s.push_back((char)('a' + *letras[valores[i]].begin()));

            int valor = *letras[valores[i]].begin();
            letras[valores[i]].erase(valor);
            
            if (valores[i] < n-1) {
                letras[valores[i]+1].insert(valor);
            }
        }

        cout << s << endl;
    }
    return 0;
}
