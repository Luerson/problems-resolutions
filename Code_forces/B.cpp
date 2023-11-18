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
        ll resp = 0;
        cin >> n;

        valores.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> valores[i];
        }

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ll maximum = 0;
                ll minimum = LONG_LONG_MAX;

                for (int j = 0; j < n; j += i)
                {
                    ll sum = 0;
                    for (int k = 0; k < i; k++)
                    {
                        sum += valores[j + k];
                    }

                    if (sum > maximum)
                    {
                        maximum = sum;
                    }
                    if (sum < minimum)
                    {
                        minimum = sum;
                    }
                }

                if (maximum - minimum > resp)
                {
                    resp = maximum - minimum;
                }

                maximum = 0;
                minimum = LONG_LONG_MAX;

                for (int j = 0; j < n; j += (n / i))
                {
                    ll sum = 0;
                    for (int k = 0; k < (n / i); k++)
                    {
                        sum += valores[j + k];
                    }

                    if (sum > maximum)
                    {
                        maximum = sum;
                    }
                    if (sum < minimum)
                    {
                        minimum = sum;
                    }
                }

                if (maximum - minimum > resp)
                {
                    resp = maximum - minimum;
                }
            }
        }

        cout << resp << endl;
    }
    return 0;
}
