#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000;

// estruturas de dados do problema
int valores[MAX][MAX];

// variáveis do problema
int L, C, A, B;

pair<int, int> solve(int x, int y, int flagX, int flagY)
{
    if (x - 1 >= 0 && valores[x - 1][y] == 1 && !(x - 1 == flagX && y == flagY))
    {
        return solve(x - 1, y, x, y);
    }
    else if (y - 1 >= 0 && valores[x][y - 1] == 1 && !(x == flagX && y - 1 == flagY))
    {
        return solve(x, y - 1, x, y);
    }
    else if (x + 1 < L && valores[x + 1][y] == 1 && !(x + 1 == flagX && y == flagY))
    {
        return solve(x + 1, y, x, y);
    }
    else if (y + 1 < C && valores[x][y + 1] == 1 && !(x == flagX && y + 1 == flagY))
    {
        return solve(x, y + 1, x, y);
    }

    return make_pair(x, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> resp;
    cin >> L >> C >> A >> B;

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> valores[i][j];
        }
    }

    resp = solve(A - 1, B - 1, A - 1, B - 1);

    cout << resp.first + 1 << " " << resp.second + 1 << endl;

    return 0;
}
