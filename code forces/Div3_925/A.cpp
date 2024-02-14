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

string find_String(int n, int sizeS, string s) {
    if (sizeS == 3 && n == 0) {
        return s;
    }
    if (sizeS == 3) {
        return "";
    }
    if (n < 0) {
        return "";
    }

    for (int i = 1; i <= 26; i++) {
        s += ('a' + i - 1);
        if (find_String(n-i, sizeS+1, s) != "") {
            return find_String(n-i, sizeS+1, s);
        }
        s.pop_back();
    }

    return "";
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << find_String(n, 0, "") << endl;
    }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

   solve();

   return 0;
}
