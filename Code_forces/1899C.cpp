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

        ll sum = 0;
        ll maximum = LONG_LONG_MIN;

        for (int i = 0; i < n; i++)
        {
            sum += valores[i];
            if (sum > maximum)
            {
                maximum = sum;
            }

            if (sum < 0 || (i + 1 < n && abs(valores[i] % 2) == abs(valores[i + 1] % 2)))
            {
                sum = 0;
            }
        }

        cout << maximum << endl;
        ;
    }
    return 0;
}
