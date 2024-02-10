#include <bits/stdc++.h>

#define ll long long

using namespace std;

template<int P, int M>
struct str_hash {
    vector<ll> h, p;
    str_hash(string s) : h(s.size()), p(s.size()) {
        p[0] = 1, h[0] = s[0];
        for (int i = 1; i < s.size(); i++)
        p[i] = p[i-1]*P%M, h[i] = (h[i-1]*P + s[i])%M;
    }
    ll operator()(int l, int r) { // retorna hash s[l...r]
        ll hash = h[r] - (l ? h[l-1]*p[r-l+1]%M : 0);
        return hash < 0 ? hash + M : hash;
    }
};

int main() {
    string s;
    cin >> s;

    int startS, endS, startF, endF;
    stack<int> resp;

    startS = 0;
    endS = s.size() - 2;
    startF = 1;
    endF = s.size() - 1;

    str_hash<31, int(1e9 + 9)> h1 (s);

    while (endS >= startS) {
        if ((ll)h1(startS, endS) == (ll)h1(startF, endF)) resp.push(endS - startS + 1);
        endS--;
        startF++;
    }

    while (!resp.empty()) {
        cout << resp.top() << " ";
        resp.pop();
    }
    cout << endl;

    return 0;
}