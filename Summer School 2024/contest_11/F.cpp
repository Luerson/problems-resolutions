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

const int MAX = (int)(1e6 + 1);

vector<int> amount(MAX);
vector<ll> valores;

int block_size = 70;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int answer = 0;

    int cur_l = 0;
    int cur_r = -1;
    
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            if (amount[valores[cur_l]] == 0) {
                answer++;
            }
            amount[valores[cur_l]]++;
        }
        while (cur_r < q.r) {
            cur_r++;
            if (amount[valores[cur_r]] == 0) {
                answer++;
            }
            amount[valores[cur_r]]++;
        }
        while (cur_l < q.l) {
            if (amount[valores[cur_l]] == 1) {
                answer--;
            }
            amount[valores[cur_l]]--;
            cur_l++;
        }
        while (cur_r > q.r) {
            if (amount[valores[cur_r]] == 1) {
                answer--;
            }
            amount[valores[cur_r]]--;
            cur_r--;
        }
        answers[q.idx] = answer;
    }
    return answers;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////
    int n, q;
    cin >> n;
    vector<Query> queries;
    vector<int> ans;

    valores.resize(n);
 
    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    cin >> q;
    queries.resize(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;

        queries[i].l--;
        queries[i].r--;

        queries[i].idx = i;
    }

    ans = mo_s_algorithm(queries);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

   return 0;
}
