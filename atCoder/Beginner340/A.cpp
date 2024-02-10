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



    int A, B, C;
    cin >> A >> B >> C;

    for (int i = A; i <= B; i += C) {
        cout << i << " ";
    }
    cout << endl;


   return 0;
}
