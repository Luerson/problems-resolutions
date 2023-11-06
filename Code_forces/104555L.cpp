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

const int MAX = 26;

int alfabeto[MAX];

int k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> k;

    for (int i = 0; i < k; i++) {
        memset(alfabeto, 0, sizeof alfabeto);
        for (int j = i; j < s.size(); j += k) {
            alfabeto[s[j] - 'a']++;
        }

        int z = 0;

        for (int j = i; j < s.size(); j += k) {
            while (alfabeto[z] == 0) {
                z++;
            }
            s[j] = (char)('a' + z);
            alfabeto[z]--;
        }
    }

    cout << s << endl;
    
    return 0;
}
