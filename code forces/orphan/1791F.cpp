#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

const int mod = 1'000'000'007;

const int MAX = 200'000;

int BIT[MAX + 2];

map<int, int> valorCoordenada;
map<int, int> coordenadaValor;

void update(int x, int delta)
{
    for (; x <= MAX + 1; x += x & -x)
    {
        BIT[x] += delta;
    }
}

int query(int x)
{
    int sum = 0;
    for (; x > 0; x -= x & -x)
    {
        sum += BIT[x];
    }
    return sum;
}

void build(vector<int> ogVector, int length)
{
    int ind = 1;
    vector<int> a = ogVector;
    sortall(a);

    for (int i = 0; i < length; i++)
    {
        if (!valorCoordenada[a[i]])
        {
            valorCoordenada[a[i]] = ind;
            coordenadaValor[ind] = a[i];
            ind++;
        }
    }
    return;
}

void compress(vector<int> &vetor, int length)
{
    for (int i = 0; i < length; i++)
    {
        vetor[i] = valorCoordenada[vetor[i]];
    }
}

void decompress(vector<int> &vetor, int length)
{
    for (int i = 0; i < length; i++)
    {
        vetor[i] = coordenadaValor[vetor[i]];
    }
}

int operation(int value)
{
    int sum = 0;

    while (value > 0)
    {
        sum += value % 10;
        value /= 10;
    }

    return sum;
}

int solve(int value, int nQueries)
{
    while (nQueries > 0 && value > 9)
    {
        nQueries--;
        value = operation(value);
    }
    return value;
}

vector<int> valores;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        memset(BIT, 0, sizeof BIT);
        coordenadaValor.clear();
        valorCoordenada.clear();
        valores.clear();

        for (int i = 0; i < n; i++)
        {
            int valor;
            cin >> valor;
            valores.push_back(valor);
        }
        build(valores, n);
        compress(valores, n);

        for (int i = 0; i < q; i++)
        {
            int tipo;
            cin >> tipo;

            if (tipo == 1)
            {
                int l, r;
                cin >> l >> r;

                update(l, 1);
                update(r + 1, -1);
            }
            else
            {
                int index;
                cin >> index;
                int value = coordenadaValor[valores[index - 1]];
                int nQueries = query(index);

                int resp = solve(value, nQueries);

                cout << resp << endl;
            }
        }
    }

    return 0;
}