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

map<ll, ll> dp;

ll solve(ll valor) {
    if (valor == 1) {
        return 0;
    }

    if (dp[valor]) {
        return dp[valor];
    }

    dp[valor] = valor + solve(valor/2) + solve(valor - valor/2);

    return valor + solve(valor/2) + solve(valor - valor/2);
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ////////////////////////

    ll N;
    cin >> N;

    cout << solve(N) << endl;

   return 0;
}
