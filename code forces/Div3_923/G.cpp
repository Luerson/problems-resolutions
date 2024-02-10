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

int dp[105][105];

vector<int> valores;

int min_amount(int l, int r) {
    if (l > r) {
        return 0;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int ans = INT16_MAX;
    
    for (int i = l; i <= r; i++) {
        ans = min(ans, 1 + min_amount(l, i-1) + min_amount(i + valores[i], r));
        ans = min(ans, 1 + min_amount(l, i - valores[i]) + min_amount(i + 1, r));
    }

    for (int i = l; i <= r; i++) {
        for (int j = i+1; j <= r; j++) {
            if (valores[i] + i - 1 > j && j - valores[j] + 1 < i) {
                ans = min(ans, 2 + min_amount(l, j - valores[j]) + min_amount(i + valores[i], r));
            }
        }
    }
 
    return dp[l][r] = ans;
}

void solve() {
    int n;

    cin >> n;
    memset(dp, -1, sizeof dp);
    valores = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    cout << min_amount(0, n-1) << endl;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

   return 0;
}