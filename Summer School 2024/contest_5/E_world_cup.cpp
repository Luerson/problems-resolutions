#include<bits/stdc++.h>

using namespace std;

int A = 0, B = 1, C = 2, D = 3;
vector<pair<int, int>> jogo;

int solve(vector<int>& pontuacoes, int index) {
    int total = 0;

    if (index == 6 && pontuacoes[0] == 0 && pontuacoes[1] == 0 && pontuacoes[2] == 0 && pontuacoes[3] == 0) {
        return 1;
    }

    if (index == 6) {
        return 0;
    }

    total += pontuacoes[jogo[index].first] -= 3;
    solve(pontuacoes, index + 1);
    total += pontuacoes[jogo[index].first] += 3;

    total += pontuacoes[jogo[index].second] -= 3;
    solve(pontuacoes, index + 1);
    total += pontuacoes[jogo[index].second] += 3;

    total += pontuacoes[jogo[index].second] -= 1;
    total += pontuacoes[jogo[index].first] -= 1;
    solve(pontuacoes, index + 1);
    total += pontuacoes[jogo[index].second] += 1;
    total += pontuacoes[jogo[index].first] += 1;

    return total;
}

int main() {
    int t;
    cin >> t;

    jogo.push_back(make_pair(A, B));
    jogo.push_back(make_pair(A, C));
    jogo.push_back(make_pair(A, D));
    jogo.push_back(make_pair(B, C));
    jogo.push_back(make_pair(B, D));
    jogo.push_back(make_pair(C, D));

    for (int k = 1; k <= t; k++) {
        vector<int> pontuacoes;
        pontuacoes.resize(4);

        for (int i = 0; i < 4; i++) {
            cin >> pontuacoes[i];
        }

        int resp = solve(pontuacoes, 0);

        if (resp == 1) {
            cout << "Case #" << k << " Yes" << endl;
        } else if (resp > 1) {
            cout << "Case #" << k << " No" << endl;
        } else {
            cout << "Case #" << k << " Wrong Scoreboard" << endl;
        }
    }

    return 0;
}