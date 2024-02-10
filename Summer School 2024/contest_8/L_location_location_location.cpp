//submit failed
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MAX = 200001;

int main() {
    ll n;
    vector<ll> valoresX;
    vector<ll> valoresY;

    cin >> n;
    valoresX.resize(MAX, 0);
    valoresY.resize(MAX, 0);

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        valoresX[x + (MAX-1)/2]++;
        valoresY[y + (MAX-1)/2]++;
    }

    ll left = valoresX[0];
    ll right = n - valoresX[0];
    ll maxVal = 0, x = -100000, y = -100000;
    ll dist = 0;

    for (ll i = -100000; i <= 100000; i++) {
        maxVal += (ll)((ll)valoresX[i + (MAX-1)/2]*(ll)(i + 100000));
    }

    dist = maxVal;

    for (ll i = -99999; i <= 100000; i++) {
        dist -= right;
        right -= valoresX[i + (MAX-1)/2];
        dist += left;

        if (dist < maxVal) {
            maxVal = dist;
            x = i;
        }

        left += valoresX[i + (MAX-1)/2];
    }

    left = valoresY[0];
    right = n - valoresY[0];
    maxVal = 0;
    dist = 0;

    for (ll i = -100000; i <= 100000; i++) {
        maxVal += (ll)((ll)valoresY[i + (MAX-1)/2]*(ll)(i + 100000));
    }

    dist = maxVal;

    for (ll i = -99999; i <= 100000; i++) {
        dist -= right;
        right -= valoresY[i + (MAX-1)/2];
        dist += left;

        if (dist < maxVal) {
            maxVal = dist;
            y = i;
        }

        left += valoresY[i + (MAX-1)/2];
    }

    cout << x << " " << y << endl;

    return 0;
}