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

void solve()
{
    ll n, x, resp = 0;
    cin >> n >> x;

    vector<ll> valores(n);
    map<ll, int> somas;

    somas[0] = 1;

    for (int i = 0; i < n; i++)
    {
        ll valor;
        cin >> valor;

        valores[i] = valor + (i > 0 ? valores[i - 1] : 0);
    }

    for (int i = 0; i < n; i++)
    {
        if (somas[valores[i] - x])
        {
            resp += somas[valores[i] - x];
        }
        somas[valores[i]]++;
    }

    cout << resp << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    solve();

    return 0;
}