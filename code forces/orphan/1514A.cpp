#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

   int t;
   cin >> t;

   while (t--) {
    int n, can = 0;
    cin >> n;

    map<int, int> divisores;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;

        vector<ll> fiv_valor = trial_division1(valor);

        for (int i = 0; i < fiv_valor.size(); i++) {
            divisores[fiv_valor[i]]++;
        }

        for (int i = 0; i < fiv_valor.size(); i++) {
            if (divisores[fiv_valor[i]]%2 != 0) {
                can = 1;
            }
        }
    }

    if (can) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
   }

   return 0;
}
