#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

const int mod = 1'000'000'007;
const int MAX = (1 << 17);

vector<int> valores;
vector<int> tree;

void build(int node, int start, int end, int level)
{
    if (start == end)
    {
        tree[node] = valores[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, level - 1);
        build(2 * node + 1, mid + 1, end, level - 1);

        if (level % 2 != 0)
        {
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        }
        else
        {
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }
}

void update(int node, int start, int end, int idx, int val, int level)
{
    if (start == end)
    {
        valores[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;

        if (start <= idx && idx <= mid)
        {
            update(2 * node, start, mid, idx, val, level - 1);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val, level - 1);
        }

        if (level % 2 != 0)
        {
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        }
        else
        {
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    valores.clear();
    tree.clear();

    valores.resize((1 << n));
    tree.resize(4 * (1 << n));

    for (int i = 0; i < (1 << n); i++)
    {
        cin >> valores[i];
    }

    build(1, 0, (1 << n) - 1, n);

    for (int i = 0; i < m; i++)
    {
        int p, b;
        cin >> p >> b;

        update(1, 0, (1 << n) - 1, p - 1, b, n);
        cout << tree[1] << " ";
    }
    cout << endl;

    return 0;
}