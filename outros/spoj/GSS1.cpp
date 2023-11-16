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

const int MAX = 50'000;

// estruturas de dados do problema
vector<int> valores;
vector<int> treeSum;
vector<pair<int, int>> treeMax;

int n;

void buildSum(int node, int start, int end)
{
    if (start == end)
    {
        // Leaf node will have a single element
        treeSum[node] = valores[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        buildSum(2 * node, start, mid);
        // Recurse on the right child
        buildSum(2 * node + 1, mid + 1, end);
        // Internal node will have the sum of both of its children
        treeSum[node] = treeSum[2 * node] + treeSum[2 * node + 1];
    }
}

int querySum(int node, int start, int end, int l, int r)
{
    if (r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if (l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return treeSum[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = querySum(2 * node, start, mid, l, r);
    int p2 = querySum(2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

void buildMax(int node, int start, int end)
{
    if (start == end)
    {
        // Leaf node will have a single element
        treeMax[node] = make_pair(start, end);
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        buildMax(2 * node, start, mid);
        // Recurse on the right child
        buildMax(2 * node + 1, mid + 1, end);
        // Internal node will have the sum of both of its children
        if (querySum(1, 0, n - 1, treeMax[2 * node].first, treeMax[2 * node].second) > querySum(1, 0, n - 1, treeMax[2 * node + 1].first, treeMax[2 * node + 1].second))
        {
            treeMax[node].first = treeMax[2 * node].first;
            treeMax[node].second = treeMax[2 * node].second;
        }
        else
        {
            treeMax[node].first = treeMax[2 * node + 1].first;
            treeMax[node].second = treeMax[2 * node + 1].second;
        }

        if (querySum(1, 0, n - 1, treeMax[2 * node].first, treeMax[2 * node + 1].second) > querySum(1, 0, n - 1, treeMax[node].first, treeMax[node].second))
        {
            treeMax[node].first = treeMax[2 * node].first;
            treeMax[node].second = treeMax[2 * node + 1].second;
        }
    }
}

pair<int, int> queryMax(int node, int start, int end, int l, int r)
{
    if (r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return make_pair(0, 0);
    }
    if (l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return make_pair(treeMax[node].first, treeMax[node].second);
    }

    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    pair<int, int> coordinates;

    pair<int, int> left = queryMax(2 * node, start, mid, l, r);
    pair<int, int> right = queryMax(2 * node + 1, mid + 1, end, l, r);

    if (querySum(1, 0, n - 1, left.first, left.second) > querySum(1, 0, n - 1, right.first, right.second))
    {
        coordinates.first = left.first;
        coordinates.second = left.second;
    }
    else
    {
        coordinates.first = right.first;
        coordinates.second = right.second;
    }

    if (querySum(1, 0, n - 1, treeMax[2 * node].first, treeMax[2 * node + 1].second) > querySum(1, 0, n - 1, treeMax[node].first, treeMax[node].second))
    {
        coordinates.first = left.first;
        coordinates.second = right.second;
    }
    return coordinates;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    valores.resize(n);
    treeSum.resize(4 * n);
    treeMax.resize(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> valores[i];
    }

    buildSum(1, 0, n - 1);
    buildMax(1, 0, n - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        pair<int, int> coordinates;
        cin >> l >> r;

        coordinates = queryMax(1, 0, n - 1, l - 1, r - 1);
        cout << querySum(1, 0, n - 1, coordinates.first, coordinates.second);
    }

    return 0;
}