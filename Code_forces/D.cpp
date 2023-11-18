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
map<int, int> frequencia;

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
        valores.clear();
        frequencia.clear();

        valores.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> valores[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (valores[i] == 2)
            {
                valores[i] = 1;
            }

            if (!frequencia[valores[i]])
                frequencia[valores[i]] = 1;
            else
                frequencia[valores[i]]++;
        }

        for (auto it = frequencia.begin(); it != frequencia.end(); it++)
        {
            if (it->second >= 2)
            {
                resp += ((ll)it->second * (ll)(it->second - 1)) / 2;
            }
        }

        cout << resp << endl;
    }
    return 0;
}