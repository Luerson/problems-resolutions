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

const int MAX = 100'000;

//compressão de coordenadas
map<int, int> valorCoordenada; //a key é o valor original e value é a coordenada
map<int, int> coordenadaValor; // a key é a coordenada e value é o valor original

int BIT[MAX + 1];

//Essa função preenche os valores das maps de conversão a partir do vetor original
void build(vector<int> OgVetor, int n) {
    int ind = 1;
    vector<int> a = OgVetor;
    sort(a.begin(), a.end());


    for(int i = 0; i < n; i++) {
        if (!valorCoordenada[a[i]]) {
            valorCoordenada[a[i]] = ind;
            coordenadaValor[ind] = a[i];
            ind++;
        }
    }


    return;
}


//Recebe o vetor com os valores originais e converte para suas coordenadas
void compress(vector<int>& vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = valorCoordenada[vetor[i]];
    }
}


//Recebe o vetor com as coordenadas e converte para os valores originais
void decompress(vector<int>& vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = coordenadaValor[vetor[i]];
    }
}

void update(int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAX + 1; x += x&-x)
          BIT[x] += delta;
}


int query(int x)//returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}


long long solve(vector<pair<int, int>> dados) {
    vector<int> OgVector;
    ll inversions = 0;
    int n = dados.size();

    for (int i = 0; i < n; i++) {
        OgVector.push_back(dados[i].second);
    }

    valorCoordenada.clear();
    coordenadaValor.clear();

    build(OgVector, n);
    compress(OgVector, n);

    memset(BIT, 0, sizeof BIT);

    for (int i = 0; i < n; i++) {
        inversions += query(MAX) - query(OgVector[i]);
        update(OgVector[i], 1);
    }

    return inversions;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int X, Y;
    int H, V;
    cin >> X >> Y;
    cin >> H >> V;

    vector<pair<int, int>> horizontal;
    vector<pair<int, int>> vertical;

    for (int i = 0; i < H; i++) {
        int l, r;

        cin >> l >> r;
        
        horizontal.push_back(make_pair(l, r));
    }

    sortall(horizontal);
    
    for (int i = 0; i < V; i++) {
        int up, bottom;

        cin >> up >> bottom;

        vertical.push_back(make_pair(up, bottom));
    }

    sortall(vertical);

    long long countInversions = 0;
    long long resp;

    countInversions += solve(horizontal);
    countInversions += solve(vertical);

    resp = (horizontal.size() + 1)*(vertical.size() + 1) + countInversions;

    cout << resp << endl;

    return 0;
}
