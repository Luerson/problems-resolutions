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

const int MAX = 26;

string s;

vector<vector<int>> tree;

void build(int node, int start, int end)
{
    tree[node].resize(MAX);

    if (start == end)
    {
        // Leaf node will have a single element
        tree[node][s[start] - 'a']++;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2 * node, start, mid);
        // Recurse on the right child
        build(2 * node + 1, mid + 1, end);

        for (int i = 0; i < MAX; i++)
        {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }
}

void update(int node, int start, int end, int idx, char val)
{
    if (start == end)
    {
        // Leaf node
        s[idx] = val;

        for (int i = 0; i < MAX; i++)
        {
            tree[node][i] = 0;
        }

        tree[node][val - 'a']++;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        // Internal node will have the sum of both of its children

        for (int i = 0; i < MAX; i++)
        {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }
}

vector<int> query(int node, int start, int end, int l, int r)
{
    if (r < start or end < l)
    {
        vector<int> nulo;
        nulo.resize(MAX);
        // range represented by a node is completely outside the given range
        return nulo;
    }
    if (l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    vector<int> p1 = query(2 * node, start, mid, l, r);
    vector<int> p2 = query(2 * node + 1, mid + 1, end, l, r);

    vector<int> p3;
    p3.resize(MAX);

    for (int i = 0; i < MAX; i++)
    {
        p3[i] = p1[i] + p2[i];
    }
    return p3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    tree.resize(4 * s.size());
    build(1, 0, s.size() - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int tipo;
        cin >> tipo;

        if (tipo == 1)
        {
            int pos;
            char novo;

            cin >> pos >> novo;

            update(1, 0, s.size() - 1, pos - 1, novo);
        }
        else
        {
            int l, r, cont = 0;
            cin >> l >> r;

            vector<int> resp = query(1, 0, s.size() - 1, l - 1, r - 1);

            for (int j = 0; j < MAX; j++)
            {
                cont += (resp[j] > 0 ? 1 : 0);
            }

            cout << cont << " ";
        }
    }
    cout << endl;
    return 0;
}
