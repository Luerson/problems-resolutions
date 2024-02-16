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

const int MAX = 1e5 + 10;
const int block_size = 320;
int n, m;

vector<ll> a(MAX);
vector<ll> last(MAX);
vector<ll> dist(MAX);

void get(int i) {
    if (i + a[i] > n || i/block_size != (i+a[i])/block_size) dist[i] = 0, last[i] = i;
    else dist[i] = dist[i + a[i]] + 1, last[i] = last[i + a[i]];
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i > 0; i--) {
        get(i);
    }

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op) {
            int lastHole, distHole = 0, hole;
            cin >> hole;

            for (; hole <= n; hole = hole + a[hole]) {
                distHole += dist[hole] + 1;
                lastHole = last[hole];

                hole = last[hole];
            }

            cout << lastHole << " " << distHole << endl;
        } else {
            int hole, newPower;
            cin >> hole >> newPower;
            a[hole] = newPower;

            for (int j = hole; j > 0 && j/block_size == hole/block_size; j--) {
                get(j);
            }  
        }
    }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    solve();

   return 0;
}
