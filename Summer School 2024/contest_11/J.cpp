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

const int MAX = 1e5+10;

int n, m;

ll a[MAX];
set<pair<ll, pair<ll, ll>>> groups;

ll ta[MAX], tb[MAX];


// Fenwick tree com range update && range query
void add(ll x,ll k){
	for(int i=x;i<=n;i+=i&-i)ta[i]+=k,tb[i]+=k*(x-1);
}

ll query(int x){
	ll ret=0;
	for(int i=x;i;i-=i&-i)ret+=x*ta[i]-tb[i];
	return ret;
}

void merge(int l, int r, int x) {
    int pp = l, rr = r;

    int pl, pr, px, Tl, Tr;
    //debug2(get<0>(*p), get<1>(*p));
  
    while (pp <= rr) {
        auto p = --groups.upper_bound({pp, {1e18, 1e18}});
        if (p->first > rr || p->second.first < pp)
        {
            break;
        }

        pl = p->first;
        pr = p->second.first;
        px = p->second.second;

        Tl = max(l, pl);
        Tr = min(r, pr);
        add(Tl, abs(x-px)), add(Tr+1, -abs(x-px));
        groups.erase(p);

        if (Tl > pl) {
            groups.insert({pl, {Tl-1, px}});
        }

        if (Tr < pr) {
            groups.insert({Tr+1, {pr, px}});
        }

        pp = Tr+1;

        //debug2(pl, pr);
    }

    groups.insert({l, {r, x}});
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        a[i] = i;
        groups.insert({i, {i, i}});
    }

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;

            merge(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;

            printf("%lld\n", query(r) - query(l-1));
        }
    }
}

int main() {
//    ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   ////////////////////////

    solve();

   return 0;
}
