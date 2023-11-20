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

// estruturas de dados do problema
vector<int> valores;

// variáveis do problema
int n;

ll solve()
{
    ll sum = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (valores[i] > valores[i + 1])
        {
            int k = valores[i] / valores[i + 1] + (valores[i] % valores[i + 1] != 0);
            valores[i] = valores[i] / k;
            sum += k - 1;
        }
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int total = 0;
        cin >> n;
        valores.clear();

        valores.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> valores[i];
        }

        cout << solve() << endl;
    }
    return 0;
}
