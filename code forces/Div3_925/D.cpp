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

void solve() {
    int t;
    cin >> t;

    while (t--) {
        ll n, x, y, total = 0;
        cin >> n >> x >> y;

        vector<ll> restoX(n);
        vector<ll> restoY(n);
        map<pair<ll, ll>, ll> indexes;

        for (int i = 0; i < n; i++) {
            ll valor;
            cin >> valor;

            restoX[i] = valor%x;
            restoY[i] = valor%y;

            indexes[make_pair(restoX[i], restoY[i])]++;
        }

        for (int i = 0; i < n; i++) {
            indexes[make_pair(restoX[i], restoY[i])]--;

            total += indexes[make_pair((x - restoX[i])%x, restoY[i])];
        }

        cout << total << endl;
    }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

   solve();

   return 0;
}
