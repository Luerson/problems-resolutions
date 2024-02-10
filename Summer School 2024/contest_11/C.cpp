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

const int MAX = 200'000;
ll BIT[MAX + 1];

void update(int x, int delta) // add "delta" at index "x"
{
    for (; x <= MAX; x += x & -x)
        BIT[x] += delta;
}

ll query(int x) // returns the sum of first x elements in given array a[]
{
    ll sum = 0;
    for (; x > 0; x -= x & -x)
        sum += BIT[x];
    return sum;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    memset(BIT, 0, sizeof BIT);
    vector<int> valores(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int valor;
        cin >> valor;

        valores[i] = valor;
        update(i, valor);
    }

    for (int i = 0; i < q; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;

        if (z == 1)
        {
            int valor = valores[x];
            valores[x] = y;
            update(x, 0 - valor);
            update(x, y);
        }
        else
        {
            cout << query(y) - query(x - 1) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    solve();

    return 0;
}