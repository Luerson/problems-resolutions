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

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
////////////////////////

map<int, int> valores1;
map<int, int> valores2;

int t;
cin >> t;
while (t--) {
    int n, maisUm, cont = 0;
    cin >> n;

    valores1.clear();
    valores2.clear();

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;

        valores1[valor]++;
    }

    for (auto a = --valores1.end(); a != valores1.begin(); a--) {
        if (a->second == 1) {
            valores2[a->first + (!valores2[a->first+1])]++;
        } else {
            valores2[a->first]++;
            valores2[a->first+1]++;
        }
    }

    if (valores1.begin()->second > 1) {
        valores2[valores1.begin()->first]++;
        valores2[valores1.begin()->first+1]++;
    } else {
        valores2[valores1.begin()->first]++;
    }

    cout << valores2.size() << endl;
}

return 0;
}