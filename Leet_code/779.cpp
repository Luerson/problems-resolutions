class Solution {
public:
    int kthGrammar(int n, int k) {
        long long referencia = (1<<(n - 1))/2;
        long long end = 1<<(n-1);
        long long start = 0;
        int ehImpar = n % 2 != 0;

        if (k == 1) {
            return 0;
        }

        return solve(ehImpar, ehImpar, referencia, k, start, end);
    }

    int solve(int numeroAtual, int ehImpar, int posAtual, int k, int start, int end) {
        if (k == posAtual) {return numeroAtual;}
        if (k == posAtual + 1 && ehImpar) {return numeroAtual;}
        if (k == posAtual + 1 && !ehImpar) {return !numeroAtual;}

        if (k > posAtual) {
            start = posAtual;
            return solve(numeroAtual, !ehImpar, (end + start)/2, k, start, end);
        }

        end = posAtual;
        return solve(!numeroAtual, !ehImpar, (end + start)/2, k, start, end);
    }
};