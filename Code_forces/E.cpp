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

int solve()
{
    int ordenado = 1;
    int min = INT32_MAX;
    int indexMin;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + 1 < n && valores[i + 1] < valores[i])
        {
            ordenado = 0;
        }
        if (valores[i] <= min && !ordenado)
        {
            return -1;
        }
        else if (valores[i] <= min)
        {
            min = valores[i];
            indexMin = i;
        }
    }

    return indexMin;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
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
