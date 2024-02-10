#include <bits/stdc++.h>


#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()


#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;


#define pii pair<int, int>
#define pll pair<ll, ll>


typedef long long ll;
typedef long double ld;


const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;


const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;


using namespace std;

const int MAXN = 200'000;

//que dará origem à segTree
ll tree[4*MAXN];
ll lazy[4*MAXN];

vector<ll> valoresA;
vector<ll> valoresB;


void build(int node, int start, int end)
{
    if (start == end)
    {
        // Leaf node will have a single element
        tree[node] = valoresA[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2 * node, start, mid);
        // Recurse on the right child
        build(2 * node + 1, mid + 1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}


void updateRange(int node, int start, int end, int l, int r, ll val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node]; // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start > end || start > r || end < l) // Current segment is not within range [l, r]
        return;
    if(start >= l && end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val); // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val); // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}


ll queryRange(int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node]; // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start >= l && end <= r) // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r); // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

void solve() {
    ll n, m;
    
    cin >> n >> m;
    valoresA.resize(n);
    valoresB.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> valoresA[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> valoresB[i];
    }

    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);

    build(1, 0, n-1);

    for (int i = 0; i < m; i++) {
        int index = valoresB[i];

        ll valorA = queryRange(1, 0, n-1, index, index);
        updateRange(1, 0, n-1, index, index, (0 - valorA));
        updateRange(1, 0, n-1, 0, n-1, valorA/n);

        valorA %= n;

        if (index + valorA < n) {
            updateRange(1, 0, n-1, index+1, index + valorA, 1);
        } else {
            updateRange(1, 0, n-1, index+1, n-1, 1);
            updateRange(1, 0, n-1, 0, (index + valorA)%n, 1);
        }

        valorA = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << queryRange(1, 0, n-1, i, i) << " ";
    }
    cout << endl;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    solve();

   return 0;
}
