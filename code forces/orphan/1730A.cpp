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
    int n, c, sum = 0;;
    vector<int> per_orbit(101);

    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;

        per_orbit[valor]++;
    }

    for (int i = 0; i < 101; i++) {
        sum += min(c, per_orbit[i]);
    }

    cout << sum << endl;
}

return 0;
}
