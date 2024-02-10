#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

const int mod = 1'000'000'007;
const int MAX = 100'000;

vector<int> valores;

string s;

vector<int> mainTree;
vector<int> supportTree;
vector<int> lazy;

void buildSupport(int node, int start, int end)
{
    if (start == end)
    {
        supportTree[node] = valores[start];
    }
    else
    {
        int mid = (start + end) / 2;
        buildSupport(2 * node, start, mid);
        buildSupport(2 * node + 1, mid + 1, end);
        supportTree[node] = (supportTree[2 * node] ^ supportTree[2 * node + 1]);
    }
}

void buildMain(int node, int start, int end)
{
    if (start == end)
    {
        mainTree[node] = valores[start] * (s[start] == '1');
    }
    else
    {
        int mid = (start + end) / 2;
        buildMain(2 * node, start, mid);
        buildMain(2 * node + 1, mid + 1, end);
        mainTree[node] = (mainTree[2 * node] ^ mainTree[2 * node + 1]);
    }
}

void updateRange(int node, int start, int end, int l, int r)
{
    if (lazy[node] != 0)
    {
        mainTree[node] = (supportTree[node] ^ mainTree[node]);
        if (start != end)
        {
            lazy[node * 2] = (lazy[node * 2] ^ 1);
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] ^ 1);
        }
        lazy[node] = 0;
    }

    if (start > end || start > r || end < l)
        return;

    if (start >= l && end <= r)
    {
        mainTree[node] = (supportTree[node] ^ mainTree[node]);
        if (start != end)
        {
            lazy[node * 2] = (lazy[node * 2] ^ 1);
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] ^ 1);
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r);
    updateRange(node * 2 + 1, mid + 1, end, l, r);
    mainTree[node] = (mainTree[node * 2] ^ mainTree[node * 2 + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        valores.clear();
        mainTree.clear();
        supportTree.clear();
        lazy.clear();

        valores.resize(n);
        mainTree.resize(4 * n);
        supportTree.resize(4 * n);
        lazy.resize(4 * n);

        for (int i = 0; i < n; i++)
        {
            cin >> valores[i];
        }

        cin >> s;

        buildSupport(1, 0, n - 1);
        buildMain(1, 0, n - 1);

        int q;
        cin >> q;

        for (int i = 0; i < q; i++)
        {
            int tipo;
            cin >> tipo;

            if (tipo == 1)
            {
                int l, r;
                cin >> l >> r;
                updateRange(1, 0, n - 1, l - 1, r - 1);
            }
            else
            {
                int g;
                cin >> g;

                if (lazy[1] != 0)
                {
                    mainTree[1] = (mainTree[1] ^ supportTree[1]);
                    lazy[1] = 0;
                    if (0 != n - 1)
                    {
                        lazy[2] = (lazy[2] ^ 1);
                        lazy[3] = (lazy[3] ^ 1);
                    }
                }

                if (g == 1)
                {
                    cout << mainTree[1] << " ";
                }
                else
                {
                    cout << (mainTree[1] ^ supportTree[1]) << " ";
                }
            }
        }

        cout << endl;
    }
}