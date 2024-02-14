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

int calc_media(vector<int>& valores) {
    int soma = 0;

    for (int i = 0; i < valores.size(); i ++) {
        soma += valores[i];
    }

    return soma/valores.size();
}

bool eh_Possivel(vector<int>& valores, int media) {
    for (int i = 0; i < valores.size(); i++) {
        if (valores[i] < media) {
            return false;
        }

        int dif = valores[i] - media;

        if (i != valores.size() - 1) {
            valores[i] -= dif;
            valores[i+1] += dif;
        }
    }

    return true;
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

        int media = calc_media(valores);

        if (eh_Possivel(valores, media)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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
