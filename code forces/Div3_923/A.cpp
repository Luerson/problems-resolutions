#include <bits/stdc++.h>
using namespace std;

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
vector<char> valores;

//variáveis do problema
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        valores.clear();
        valores.resize(n);

        int iS, iF;

        iS = 0;
        iF = n-1;

        for (int i = 0; i < n; i++) {
            cin >> valores[i];
        }

        for (; iS < n; iS++) {
            if (valores[iS] == 'B') {
                break;
            }
        }

        for (; iF >= 0; iF--) {
            if (valores[iF] == 'B') {
                break;
            }
        }   

        if (iS <= iF && n != 1) {
            cout << iF-iS+1 << endl;
        } else if (n == 1 && valores[0] == 'B') {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
