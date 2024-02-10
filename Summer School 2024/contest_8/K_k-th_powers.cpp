#include <bits/stdc++.h>

#define endl '\n'
#define MOD ((long long)1000000007)

typedef long long ll;
// typedef mod_int<MOD> mint;

using namespace std;


template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<(int)1e9+7> mint;


// Exponenciação Rápida
ll powT(ll x, ll y) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		y >>= 1;
		x = (x * x) % MOD;
	}
	return ret;
}


ll inv(ll a) {
    if (a < 0)
    {
        a += MOD;
    }
    return a <= 1 ? a : MOD - (ll) (MOD/a) * inv(MOD % a) % MOD;
}

mint evaluate_interpolation(int x, vector<mint> y) {
	int n = y.size();
	
	vector<mint> sulf(n+1, 1), fat(n, 1), ifat(n);
	for (int i = n-1; i >= 0; i--) sulf[i] = sulf[i+1] * (x - i);
	for (int i = 1; i < n; i++) fat[i] = fat[i-1] * i;
	ifat[n-1] = 1/fat[n-1];
	for (int i = n-2; i >= 0; i--) ifat[i] = ifat[i+1] * (i + 1);

	mint pref = 1, ans = 0;
	for (int i = 0; i < n; pref *= (x - i++)) {
		mint num = pref * sulf[i+1];

		mint den = ifat[i] * ifat[n-1 - i];
		if ((n-1 - i)%2) den *= -1;

		ans += y[i] * num * den;
	}
	return ans;
}


int main()
{
    ios::sync_with_stdio(0);
    // cin.tie(0);
    ////////////////////////
    ll n, k;
    vector<mint> ys;

    
    cin >> n >> k;
    
    ys.resize(k+3, 0);

    if (k+2 < n)
    {
        ys[0] = 0;
        for (int i = 1; i <= k+2; i++)
        {
            ys[i] = ys[i-1] + powT(i, k);
            // cout << "ys[" << i << "] = " << ys[i] << endl;
        }
    
        mint temp;
        cout << evaluate_interpolation(n, ys) << endl;
    }
    else
    {
        ll ans = 0;
        
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans + powT(i, k)) % MOD;
        }
        
        cout << ans << endl;
    }


    return 0;
}