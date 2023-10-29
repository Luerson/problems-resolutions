#define A 0
#define E 1
#define I 2
#define O 3
#define U 4

int N;

long long dp[5][21'000];
#define dpUpdate dp[last][currentAmount]

class Solution {
public:
    int countVowelPermutation(int n) {
        long long totalPossivel = 0;
        N = n;

        memset(dp, -1, sizeof dp);

        for (int i = A; i <= U; i++) {
            totalPossivel += solve(i, 1);
            totalPossivel %= 1'000'000'007;
        }

        return totalPossivel;
    }

    long long solve(int last, int currentAmount) {
        if (currentAmount == N) {
            dpUpdate = 1;
            return dpUpdate;
        }

        if (dpUpdate != -1) {
            return dpUpdate;
        }

        long long total = 0;

        if (last == A) {
            total += solve(E, currentAmount + 1);
        } else if (last == E) {
            total += solve(A, currentAmount + 1);
            total += solve(I, currentAmount + 1);
        } else if (last == I) {
            total += solve(A, currentAmount + 1);
            total += solve(E, currentAmount + 1);
            total += solve(O, currentAmount + 1);
            total += solve(U, currentAmount + 1);
        } else if (last == O) {
            total += solve(I, currentAmount + 1);
            total += solve(U, currentAmount + 1);
        } else if (last == U) {
            total += solve(A, currentAmount + 1);
        }

        dpUpdate = total % 1'000'000'007;

        return dpUpdate;
    }
};