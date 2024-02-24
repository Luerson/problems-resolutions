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

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 37;
const ll PRIME_HASH2 = 31;

using namespace std;

bool he_can(ll k, ll x, ll a, ll ogA, ll coins) {
    if (x == 0 && a*k > ogA) {
        return true;
    }

    if (x == 0 || a <= 0) {
        return false;
    }

    coins = (ogA - a)/(k - 1) + 1;

    return he_can(k, x-1, a - coins, ogA, coins);
}

void solve() {
    ll k, x, a;
    cin >> k >> x >> a;

    if (he_can(k, x, a, a, 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}