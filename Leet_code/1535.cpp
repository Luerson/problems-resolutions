class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int valor = arr[0];
        int victs = 0;
        int inicio = 0;
        int final = 1;

        while (final < arr.size()) {
            if (victs == k) {
                return valor;
            }

            int newVal = max(arr[inicio], arr[final]);

            if (newVal != valor) {
                valor = newVal;
                victs = 0;
                inicio = final;
                final += 1;
            } else {
                final += 1;
            }

            victs++;
        }

        return valor;
    }
};