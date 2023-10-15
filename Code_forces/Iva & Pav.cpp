#include <bits/stdc++.h>
using namespace std;




//Declarações de variáveis
#define endl '\n'
#define ll long long
#define ld long double
#define llu unsigned long long int




//Leituras em scanf();
#define si(x) scanf("%d", &x)
#define sd(x) scanf("%Lf", &x)
#define sl(x) scanf("%lld", &x)




//Prompt usando printf();
#define pi(x) printf("%d", x);
#define pd(x) printf("%lf", x);
#define pl(x) printf("%lld", x);




//Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;




//Resumo de métodos das estruturas de dados
#define pb push_back
#define mp make_pair

//Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define MsetZ(x) memset(x, 0, sizeof x)
#define MsetN(x) memset(x, -1, sizeof x)
#define sortall(x) sort(all(x))

// Resumo de iteradoes
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k, k<n? i<n: i>n; k<n? i += 1: i -= 1)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)




//Declaração de estruturas de dados
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vvpii;

int segTree[4*200000];
int a[200000];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        segTree[v] = a[tl];
    } else {
        int tm = (tl + tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        segTree[v] = segTree[v*2] & segTree[v*2 + 1];
    }
}

int andOperation(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr) {
        return segTree[v];
    }
    int tm = (tl + tr) / 2;
    return andOperation(v*2, tl, tm, l, min(r, tm)) & andOperation(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int binarySearch(int low, int high, int key, int tl) {
    int pos = -1;
    int start = low;
    int end = high;

    while(low <= high) {
        int mid = (low + high)/2;
        int maxUntilNow = andOperation(1, tl, end, start, mid);

        if (maxUntilNow < key) {
            high = mid-1;
        }
        else if (maxUntilNow >= key) {
            pos = mid;
            low = mid+1;
        }
    }

    return pos;
}

//valor comum em problemas com módulo
const int mod = 1000000007;

int main() {
    int t;
    
    si(t);

    while(t--) {
        int n, q;

        cin >> n;
        fo(i, n) {
            cin >> a[i];
        }

        build(a, 1, 0, n-1);

        cin >> q;
        fo(i, q) {
            int l, k;
            cin >> l;
            cin >> k;
            
            l--;

            int result = binarySearch(l, n-1, k, 0);
            if (result != -1)
                result++;

            cout << to_string(result);
            if (i != q-1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}