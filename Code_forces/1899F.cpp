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
int n, q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        valores.clear();

        valores.resize(q);

        for (int i = 0; i < q; i++)
        {
            cin >> valores[i];
        }

        for (int i = 1; i < n; i++)
        {
            cout << i << " " << i + 1 << endl;
        }

        int previous = 2;

        for (int i = 0; i < q; i++)
        {
            int newNode = valores[i] + 1;

            if (previous == newNode)
            {
                cout << "-1 -1 -1" << endl;
            }
            else
            {
                cout << "1 " << previous << " " << newNode << endl;
                previous = newNode;
            }
        }
    }
    return 0;
}