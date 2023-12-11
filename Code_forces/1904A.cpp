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
set<pair<ll, ll>> localizacoes;

// variáveis do problema
ll a, b, X1, Y1, X2, Y2, resp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        resp = 0;
        localizacoes.clear();
        cin >> a >> b >> X1 >> Y1 >> X2 >> Y2;

        for (int i = 0; i < 2; i++)
        {
            localizacoes.insert(make_pair(X1 + a, Y1 + b));
            localizacoes.insert(make_pair(X1 + a, Y1 - b));
            localizacoes.insert(make_pair(X1 - a, Y1 + b));
            localizacoes.insert(make_pair(X1 - a, Y1 - b));

            if (a == b)
                break;
            swap(a, b);
        }

        for (int i = 0; i < 2; i++)
        {
            resp += (localizacoes.find((make_pair(X2 + a, Y2 + b))) != localizacoes.end() ? 1 : 0);
            resp += (localizacoes.find((make_pair(X2 + a, Y2 - b))) != localizacoes.end() ? 1 : 0);
            resp += (localizacoes.find((make_pair(X2 - a, Y2 + b))) != localizacoes.end() ? 1 : 0);
            resp += (localizacoes.find((make_pair(X2 - a, Y2 - b))) != localizacoes.end() ? 1 : 0);
            if (a == b)
                break;
            swap(a, b);
        }

        cout << resp << endl;
    }
    return 0;
}