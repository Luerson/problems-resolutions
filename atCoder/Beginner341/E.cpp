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

const int MAX = 5e5 + 10;

using namespace std;

int n, q;
string s;

vector<ll> BIT(MAX); 

void update(int x, ll val) {
    if (x < 0) {
        return;
    }

    for (; x < MAX; x += x&-x) {
        BIT[x] += val;
        if (x == 0) break;
    }
}

ll query(int x) {
    ll sum = 0;

    if (x < 0) {
        return 0;
    }

    for (; x >= 0; x -= x&-x) {
        sum += BIT[x];
        if (x == 0) break;
    }

    return sum;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ////////////////////////
    
    cin >> n >> q;
    cin >> s;

    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1])
            update(i, 1);
    }

    for (int i = 0; i < q; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        l--;
        r--;

        if (op == 1) {
            update(l-1, (query(l-1) - query(l-2) == 1? -1 : 1));
            update(r, (query(r) - query(r-1) == 1? -1 : 1));
        } else {
            
            if (query(r-1) - query(l-1) == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}