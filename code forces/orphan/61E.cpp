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

const int MAX = 1'000'000;

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

void PreencheAcumulados(vector<long long>& acumulados, vector<int> valores) {
    sortall(valores);

    for (int i = 0; i < valores.size(); i++) {
        acumulados[valores[i]]++;
    }

    for (int i = 1; i < acumulados.size(); i++) {
        acumulados[i] += acumulados[i - 1];
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

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long resp = 0;
    cin >> n;
    memset(BIT, 0, sizeof BIT);

    vector<int> valores;
    vector<long long> acumulados(MAX + 1, 0);

    for (int i = 0; i < n; i++) {
        int valor;

        cin >> valor;

        valores.push_back(valor);
    }

    build(valores, n);
    compress(valores, n);

    PreencheAcumulados(acumulados, valores);

    for (int i = 0; i < n; i++) {
        resp += (query(MAX) - query(valores[i]))*(acumulados[valores[i] - 1] - query(valores[i] - 1));
        update(valores[i], 1);
    }

    cout << resp << endl;
    
    return 0;
}
