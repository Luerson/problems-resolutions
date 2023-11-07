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
const int mod = 1000000007;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        char winner;
        int venceu = 0;
        cin >> n >> s;

        winner = s[n - 1];

        int sumA = 0;
        int sumB = 0;

        int YA = 0;
        int YB = 0;

        for (int i = 1; i <= n; i++) {
            
            for (int j = 0; j < n; j++) {
                sumA += (s[j] == 'A'? 1:0);
                sumB += (s[j] == 'B'? 1:0);

                if (sumA == i) {
                    YA += 1;
                    sumA = 0;
                    sumB = 0;
                } else if (sumB == i) {
                    YB += 1;
                    sumA = 0;
                    sumB = 0;
                }
            }

            if (winner == 'A' && YA > YB && sumA == 0 && sumB == 0) {
                venceu = 1;
                break;
            } else if (winner == 'B' && YB > YA && sumA == 0 && sumB == 0){
                venceu = 1;
                break;
            }

            YA = 0;
            YB = 0;
            sumA = 0;
            sumB = 0;
        }

        if (venceu) {
            cout << (winner == 'A'? 'A':'B') << endl;
        } else {
            cout << "?" << endl;
        }
    }
    return 0;
}
