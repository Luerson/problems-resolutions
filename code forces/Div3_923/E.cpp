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

// estruturas de dados do problema
vector<int> valores, resp;

//variáveis do problema
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        valores.clear();
        valores.resize(n);
        resp.clear();
        resp.resize(n);


        for (int i = 0; i < n; i++) {
            valores[i] = i+1;
        }

        int start = 0, end = n-1;

        for (int i = 0; i < k; i++) {
            for (int j = 0; i+j < n; j += k) {
                resp[j + i] = i%2 == 0? valores[end] : valores[start];
                i%2 == 0? end-- : start++; 
            }
        }

        for (int i = 0; i < n; i++) {
            cout << resp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
