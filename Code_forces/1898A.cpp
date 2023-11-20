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
int n, k;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int countA = 0, countB = 0;
        cin >> n >> k >> s;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                countA++;
            }
            else
            {
                countB++;
            }
        }

        if (k > countB)
        {
            int reverseA = 0;
            for (int i = 0; i < n; i++)
            {
                reverseA += (s[i] == 'A' ? 1 : 0);

                if (countB + reverseA == k)
                {
                    cout << "1\n"
                         << i + 1 << " "
                         << "B" << endl;
                    break;
                }
            }
        }
        else if (k < countB)
        {
            int reverseB = 0;
            for (int i = 0; i < n; i++)
            {
                reverseB += (s[i] == 'B' ? 1 : 0);

                if (countB - reverseB == k)
                {
                    cout << "1\n"
                         << i + 1 << " "
                         << "A" << endl;
                    break;
                }
            }
        }
        else if (k == countB)
        {
            cout << "0" << endl;
        }
    }
    return 0;
}