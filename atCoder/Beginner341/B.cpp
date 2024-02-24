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

vector<ll> valores;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    int n;
    cin >> n;
    valores.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        ll op = valores[i]/a;
        valores[i+1] += op*b;
    }

    cout << valores[n-1] << endl;

    return 0;
}