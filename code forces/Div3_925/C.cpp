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

int find_longest(vector<int>& valores) {
    int longest1 = 1;
    int maxValue = 0;

    int i = 1, j = valores.size() - 2;

    while (i < valores.size() && valores[i] == valores[i-1]) {
        longest1++;
        i++;
    }

    maxValue = max(maxValue, longest1);
    int longest2 = 1;

    while (j >= 0 && valores[j] == valores[j + 1]) {
        longest2++;
        j--;
    }

    maxValue = max(maxValue, longest2);

    if (valores[0] == valores[valores.size() - 1] && valores.size() != 1) {
        maxValue = longest1 + longest2;
    }

    if (longest1 == longest2 && longest1 == valores.size()) maxValue = valores.size();

    return maxValue;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> valores(n);
        for (int i = 0; i < n; i++) {
            cin >> valores[i];
        }

        cout << valores.size() - find_longest(valores) << endl;
    }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    solve();

   return 0;
}
