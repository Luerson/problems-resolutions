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

const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;
const int MAX = 10'000'000;

ll dp[MAX];

int inv(ll a) {
  return a <= 1 ? a : MOD_FFT - (long long)(MOD_FFT/a) * inv(MOD_FFT % a) % MOD_FFT;
}

ll fat(ll valor) {

   if (valor == 0 || valor == 1) {
      return dp[valor] = 1;
   }

   if (dp[valor] != -1) {
      return dp[valor];
   }
   return dp[valor] = (valor*fat(valor-1))%MOD_FFT;
}

ll combin(ll direita, ll esquerda, ll Pdireita, ll Pesquerda) {
   ll total = 0;

   Pdireita--;
   Pesquerda--;

   total += ((fat((Pdireita + direita)%MOD_FFT)) * inv((fat(Pdireita) * fat(direita))%MOD_FFT))%MOD_FFT;
   total %= MOD_FFT;

   total *= ((fat((Pesquerda + esquerda)%MOD_FFT) * inv((fat(Pesquerda) * fat(esquerda))%MOD_FFT)))%MOD_FFT;
   total %= MOD_FFT;

   return total;
}

void solve() {
   int t;
   cin >> t;

   memset(dp, -1, sizeof dp);

   for (int i = 0; i < MAX; i++) {
      fat(i);
   }
   
   while (t--) {
      ll t1, t2, t3, t4, total = 0;
      cin >> t1 >> t2 >> t3 >> t4;

      if (t1 == 0 && t2 == 0) {
         total = (t3 != 0 && t4 != 0? 0 : 1);
         total %= MOD_FFT;
      } else if (abs(t1 - t2) == 1){
         total += combin(t3, t4, t1 + (t2 > t1), t1 + (t2 > t1));
         total %= MOD_FFT;
      } else if (abs(t1 - t2) == 0) {
         total += combin(t3, t4, t1, t1 + 1);
         total %= MOD_FFT;

         total += combin(t3, t4, t1 + 1, t1);
         total %= MOD_FFT;
      }

      cout << total << endl;
   }
}

int main() {
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   ////////////////////////

   solve();

   return 0;
}
