#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 988'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;

ll n, m, k;

ll cal_mmc(ll n, ll m) {
    return (n*m)/(ll)__gcd(n, m);
}

ll binary_Search(ll l, ll r, ll val) {
    ll resp;
    while (l <= r) {
        ll mid = (l+r)/2;
        ll cal = mid/n + mid/m - ((ll)2)*(mid/cal_mmc(n, m));

        if (cal < val) {
            l = mid+1;
        } else if (cal > val) {
            r = mid-1;
        } else if (cal == val) {
            resp = mid;
            r = mid-1;
        }
    }

    return resp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    cin >> n >> m >> k;
    
    ll resp = binary_Search(1, 1e18, k);

    cout << resp << endl;

    return 0;
}