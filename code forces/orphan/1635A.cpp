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

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
////////////////////////

int t;
cin >> t;
while (t--) {
    int n;
    cin >> n;
    vector<ll> potencias;
    set<ll> pot_used;
    ll resp = 0;

    potencias.push_back(1);
    for (int i = 1; i <= 30; i++) {
        potencias.push_back(potencias[i-1]*(ll)2);
    }

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;

        for (int j = 0; j <= 30; j++) {
            if ((valor & potencias[j]) > 0) {
                pot_used.insert(potencias[j]);
            }
        }
    }

    for (auto a : pot_used) {
        resp += a;
    }

    cout << resp << endl;
}

return 0;
}