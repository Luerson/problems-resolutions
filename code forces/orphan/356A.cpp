#include <bits/stdc++.h>
using namespace std;

// Declarações de variáveis
#define endl '\n'
#define ll long long

// Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;

// Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

// valor comum em problemas com módulo
const int mod = 1'000'000'007;
const int MAX = 300'000;

int resp[MAX + 1];

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int n, m;
    set<int> knights;
    cin >> n >> m;
    memset(resp, 0, sizeof resp);

    for (int i = 1; i <= n; i++)
    {
        knights.insert(i);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r, x;

        cin >> l >> r >> x;

        auto comeco = knights.lower_bound(l);
        auto fim = knights.upper_bound(r);

        for (auto j = comeco; j != fim; j++)
        {
            if (*j != x && resp[*j] == 0)
            {
                resp[*j] = x;
            }
        }

        for (auto j = comeco; j != fim;)
        {
            auto helper = j;
            helper++;

            if (*j != x)
            {
                knights.erase(j);
            }
            j = helper;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << resp[i] << " ";
    }
    cout << endl;

    return 0;
}
