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

#define MAXN 30'005
#define SQRSIZE 175
 
vector<int> arr(MAXN); // original array
vector<vector<int>> block(SQRSIZE); // decomposed array
int blk_sz; // block size
 
// Time Complexity : O(sqrt(n))
int query(int l, int r, int k)
{
    int count = 0;
    while (l < r and l % blk_sz != 0 and l != 0) {
        // traversing first block in range
        count += (arr[l] > k? 1 : 0);
        l++;
    }
    while (l + blk_sz - 1 <= r) {
        // traversing completely overlapped blocks in range
        count += block[l / blk_sz].end() - upper_bound(all(block[l / blk_sz]), k);
        l += blk_sz;
    }
    while (l <= r) {
        // traversing last block in range
        count += (arr[l] > k? 1 : 0);
        l++;
    }
    return count;
}
 
// Fills values in input[]
void preprocess(vector<int> input, int n)
{
    // initiating block pointer
    int blk_idx = -1;
 
    // calculating size of block
    blk_sz = sqrt(n);
 
    // building the decomposed array
    for (int i = 0; i < n; i++) {
        arr[i] = input[i+1];

        if (i % blk_sz == 0) {
            // entering next block
            // incrementing block pointer
            blk_idx++;
        }
        block[blk_idx].push_back(arr[i]);
    }

    for (int i = 0; i < block.size(); i++) {
        sort(all(block[i]));
    }
}


void solve() {
    int n, q;
    cin >> n;

    vector<int> valores(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> valores[i];
    }

    preprocess(valores, n);

    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        cout << query(l-1, r-1, k) << endl;
    }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

   solve();

   return 0;
}
