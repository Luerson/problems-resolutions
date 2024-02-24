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

const int block_size = 450;

const int MAX = 1e6 + 1;

using namespace std;

struct Query {
    int l, r, idx;

    bool operator<(Query other) const {
        return make_pair(l/block_size, r) <
            make_pair(other.l/block_size, other.r);
    }
};

vector<Query> queries;
vector<ll> ans;
vector<ll> valores;
vector<ll> freq(MAX);
ll resp = 0;

void remove(int idx) {
    resp -= freq[valores[idx]]*valores[idx];
    freq[valores[idx]]--;
    resp -= freq[valores[idx]]*valores[idx];
}

void add(int idx) {
    resp += freq[valores[idx]]*valores[idx];
    freq[valores[idx]]++;
    resp += freq[valores[idx]]*valores[idx];
}

ll get_answear() {
    return resp;
}

void mo_s_algorithm() {
    sort(all(queries));

    int cur_l = 0;
    int cur_r = -1;

    for (auto q : queries) {
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }

        while (cur_l > q.l) {
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
    int n, t;
    cin >> n >> t;

    valores.resize(n+1);
    ans.resize(t);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        Query q;
        q.l = l;
        q.r = r;
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
