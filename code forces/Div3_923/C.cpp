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
vector<int> valoresA;
vector<int> valoresB;

set<int> setA;
set<int> setB;

//variáveis do problema
int n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        setA.clear();
        setB.clear();

        int possivel = 1;

        vector<int> valoresA;
        vector<int> valoresB;

        valoresA.resize(k+1);
        valoresB.resize(k+1);

        int exclusivosA = 0, exclusivosB = 0, repetidos = 0;

        for (int i = 0; i < n; i++) {
            int valor;
            cin >> valor;
            setA.insert(valor);
        }

        for (int i = 0; i < m; i++) {
            int valor;
            cin >> valor;
            setB.insert(valor);
        }

        for (auto a : setA) {
            if (a <= k) {
                valoresA[a] = 1;
            }
        }
        for (auto b: setB) {
            if (b <= k) {
                valoresB[b] = 1;
            }
        }

        //for (int i = 0; i < 10; i++) {
        //    debug2(i, valoresA[i]);
        //}
 
        for (int i = 1; i < k+1; i++) {
            if (valoresA[i] == 1 && valoresB[i] == 1) {
                repetidos++;
            } else if (valoresA[i] == 1 && valoresB[i] == 0){
                exclusivosA++;
            } else if (valoresB[i] == 1 && valoresA[i] == 0) {
                exclusivosB++;
            } else {
                possivel = 0;
                break;
            }
        }

        if (exclusivosA < k/2) {
            repetidos -= k/2 - exclusivosA;
            exclusivosA += k/2 - exclusivosA;
        }

        if (exclusivosB < k/2) {
            repetidos -= k/2 - exclusivosB;
            exclusivosB += k/2 - exclusivosA;
        }

        if (repetidos < 0) {
            possivel = 0;
        }

        if (possivel) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
