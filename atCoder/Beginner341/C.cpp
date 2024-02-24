#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 988'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;

int h, w, n;
string path;
vector<string> grid;

ll cells;

void verify(int i, int j, int idx) {
    if (idx > path.size() || (idx == path.size() && grid[i][j] == '.')) {
        cells++;
        return;
    }

    if (grid[i][j] == '#' || i >= h || j >= w || i < 0 || j < 0) {
        return;
    }

    if (path[idx] == 'L') j--;
    else if (path[idx] == 'R') j++;
    else if (path[idx] == 'D') i++;
    else if (path[idx] == 'U') i--;

    verify(i, j, idx+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    cells = 0;

    cin >> h >> w >> n;
    cin >> path;
    grid.resize(h);

    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            verify(i, j, 0);
        }
    }

    cout << cells << endl; 

    return 0;
}