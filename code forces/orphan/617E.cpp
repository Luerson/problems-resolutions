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

const int MAX = 1e7;
const int block_size = 320;

using namespace std;

int n, m, k;
ll resp = 0;

struct Query {
    int l, r, idx;

    bool operator<(Query other) {
        return make_pair(l/block_size, r) < 
            make_pair(other.l/block_size, other.r);
    }
};

vector<Query> queries;
vector<int> freq(MAX);
vector<int> valores;
vector<ll> ans;

void add(int idx) {
    int alvo = (valores[idx]^k);
    resp += freq[alvo];
    freq[valores[idx]]++;
}

void remove(int idx) {
    int alvo = (valores[idx]^k);
    resp -= freq[alvo];
    if (k == 0) resp++;
    freq[valores[idx]]--;
}

ll get_answear() {
    return resp;
}

void mo_s_algorithm() {
    sort(all(queries));

    int cur_l = 0;
    int cur_r = -1;

    for (auto q : queries) {
        while (cur_l < q.l-1) {
            remove(cur_l);
            cur_l++;
        }

        while (cur_l > q.l-1) {
            cur_l--;
            add(cur_l);
        }

        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }

        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }

        ans[q.idx] = get_answear();
    }
}

void solve() {
    cin >> n >> m >> k;

    valores.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> valores[i];
        valores[i] ^= valores[i-1];
    }
    cout << endl;

    ans.resize(m);
    for (int i = 0; i < m; i++) {
        Query q;
        cin >> q.l >> q.r;

        q.idx = i;

        queries.push_back(q);
    }

    mo_s_algorithm();

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    solve();
    
    return 0;
}
