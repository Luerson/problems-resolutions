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

void find_right_zeros(vector<ll>& right_zeros, vector<string> valores) {
    for (int i = 0; i < valores.size(); i++) {
        int zeros = 0;
        int j = valores[i].size() - 1;

        while (valores[i][j] == '0') {
            zeros++;
            j--;
        }

        right_zeros.push_back(zeros);
    }
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        ll n, m, total = 0;
        cin >> n >> m;

        vector<string> numeros(n);
        vector<ll> right_zeros;

        for (int i = 0; i < n; i++) {
            cin >> numeros[i];
            total += numeros[i].size();
        }

        find_right_zeros(right_zeros, numeros);
        sort(right_zeros.rbegin(), right_zeros.rend());

        for (int i = 0; i < right_zeros.size(); i += 2) {
            total -= right_zeros[i];
        }

        if (total > m) {
            cout << "Sasha" << endl;
        } else {
            cout << "Anna" << endl;
        }
    }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    solve();

   return 0;
}
