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
const int mod = 1'000'000'007;

const int MAX = 1'000;

ll BIT[MAX][MAX + 1];

char matrizChar[MAX + 1][MAX + 1];

ll N, M, lado = 1;
//
void update(int i, int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAX; x += x&-x)
        BIT[i][x] += delta;
}

ll query(int i, int x)//returns the sum of first x elements in given array a[]
{
    ll sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[i][x];
    return sum;
}

ll ehQuadrado(int i, int primeiro, int ultimo) {
    ll ultimaLinha = ultimo - primeiro + i + 1;

    if (ultimaLinha > N) {
        return 0;
    }

    for (int j = i; j < ultimaLinha; j++) {
        if (query(j, ultimo) - query(j, primeiro) != 0) {
            return 0;
        }
    }

    return ultimo - primeiro + 1;
}

ll temQuadrado(int i, int comeco, int fim) {
    ll jump = lado;
    ll maiorResposta = lado;

    while (comeco + jump < fim) {
        for (int j = comeco; j + jump < fim; j++) {
            maiorResposta = max(maiorResposta, ehQuadrado(i, j, j + jump));
        }
        jump++;
    }

    return maiorResposta;
}

void solve() {

    for (int i = 0; i < N; i++) {
        int comeco = 0;
        int fim = 0;

        while (comeco < M) {
            while (fim < M) {
                if (matrizChar[i][fim] == matrizChar[i][comeco])
                    fim++;
                else
                    break;
            }
            if (fim - comeco > lado)
                lado = max(lado, temQuadrado(i, comeco + 1, fim + 1));
            comeco = fim;
        }
    }
}
//
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(BIT, 0, sizeof BIT);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < M; j++) {
            cin >> matrizChar[i][j];

            if (j == 0 || matrizChar[i][j - 1] != matrizChar[i][j])
                update(i, j+1, 1);
        }
    }

    solve();

    cout << lado*lado << endl;

    return 0;
}