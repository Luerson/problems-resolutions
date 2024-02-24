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
    int n, m, cont = 0;
    map<int, int> trens;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        trens[v]++;
    }

    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;

        trens[v]++;
    }

    for (int i = 0; i < trens.size(); i++) {
        cont += trens[i] == 2;
    }

    cout << cont << endl;
}

return 0;
}