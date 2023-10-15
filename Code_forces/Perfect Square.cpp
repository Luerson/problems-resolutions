#include <bits/stdc++.h>
using namespace std;

//Declarações de variáveis
#define endl '\n'
#define ll long long
#define ld long double
#define llu unsigned long long int

//Debug
#define debug(x) cout << #x << "=" << x << endl;
#define debug2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;

//Resumo de métodos das estruturas de dados
#define pb push_back
#define mp make_pair

//Resumo de métodos de algoritmos
#define all(x) x.begin(), x.end()
#define MsetZ(x) memset(x, 0, sizeof x)
#define MsetN(x) memset(x, -1, sizeof x)
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
const int mod = 1'000'000'007;

char matrix[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        int cont = 0;
        cin >> n;

        memset(matrix, 0, sizeof matrix);

        fo(i, n)
            fo(j, n)
                cin >> matrix[i][j];
        
        fo(i, n/2) 
            fo(j, n/2) {
                int maximum = 0;

                maximum = max(maximum, matrix[i][j] - 'a');
                maximum = max(maximum, matrix[j][n-1-i] - 'a');
                maximum = max(maximum, matrix[n-1-i][n-1-j] - 'a');
                maximum = max(maximum, matrix[n-1-j][i] - 'a');

                cont += (('a' + maximum) - (int)matrix[i][j]);
                cont += (('a' + maximum) - (int)matrix[j][n-1-i]);
                cont += (('a' + maximum) - (int)matrix[n-1-i][n-1-j]);
                cont += (('a' + maximum) - (int)matrix[n-1-j][i]);
            }
        cout << cont << endl;
    }

    return 0;
}
