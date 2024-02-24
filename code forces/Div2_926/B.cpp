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

void solve() {
    int n, k, maxK;
    cin >> n >> k;

    maxK = 4*n - 2;

    cout << (k == maxK? k/2 + 1 : k/2 + k%2) << endl;
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