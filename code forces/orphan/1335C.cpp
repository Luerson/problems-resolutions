#include <bits/stdc++.h>
using namespace std;


//Declarações de variáveis
#define endl '\n'
#define ll long long


//Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;


//Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))


// Resumo de iteradoes
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k, k<n? i<n: i>n; k<n? i += 1: i -= 1)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)


//Declaração de estruturas de dados
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vvpii;


//valor comum em problemas com módulo
const int mod = 1000000007;

const int MAX_TRI = 500000;

long long x[2*MAX_TRI + 1];

long long y[2*MAX_TRI + 1];

long long xy[2*MAX_TRI + 1];

long long z[MAX_TRI + 1];

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, D;
    long long sum = 0;
    cin >> A >> B >> C >> D;

    x[0] = 0;
    y[0] = 0;
    z[0] = 0;
    xy[0] = 0;

    for (int i = 1; i <= 2*MAX_TRI; i++) {
        x[i] = (i < A || i > B? 0 : 1);
        y[i] = (i < B || i > C? 0 : 1);
        if (i <= MAX_TRI)
            z[i] = (i < C || i > D? 0 : 1);
        
        y[i] += y[i-1];
        x[i] += x[i-1];
    }

    for (int i = 1; i <= 2*MAX_TRI; i++) {
        if (i <= C) {
            xy[i] = 0;
            continue;
        }
        
        int upperBoundX, lowerBoundX;
        int upperBoundY, lowerBoundY;

        upperBoundX = min(B, i-1);
        lowerBoundX = A;

        upperBoundY = i - lowerBoundX;
        lowerBoundY = i - upperBoundX;

        xy[i] = y[upperBoundY] - y[lowerBoundY-1];
        xy[i] += xy[i - 1];
    }
    

    for (int i = C; i <= D; i++) {
        if (z[i]) {
            sum += xy[2*MAX_TRI] - xy[i];
        }
    }

    cout << sum << endl;

    return 0;
}
