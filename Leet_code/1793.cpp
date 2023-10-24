class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int tamanho = nums.size();
        stack<pair<int, int>> preIndices;
        stack<pair<int, int>> posIndices;
        int ultimoMenor = nums[k];
        int maiorResposta = 0;
        int iFinal = nums.size() - 1, iInicial = 0;

        for (int i = k; i < tamanho; i++) {
            if (nums[i] < ultimoMenor) {
                posIndices.push(make_pair(nums[i], i));
                ultimoMenor = nums[i];
            }
        }

        ultimoMenor = nums[k];

        for (int i = k; i >= 0; i--) {
            if (nums[i] < ultimoMenor) {
                preIndices.push(make_pair(nums[i], i));
                ultimoMenor = nums[i];
            }
        }

        while (!posIndices.empty() || !preIndices.empty()) {
            if (!posIndices.empty() && !preIndices.empty()) {
                maiorResposta = max(maiorResposta, tamanho * min(preIndices.top().first, posIndices.top().first));
                cout << tamanho << " " << maiorResposta << endl;
                if (posIndices.top().first < preIndices.top().first) {
                    tamanho -= (iFinal - posIndices.top().second + 1);
                    iFinal = posIndices.top().second - 1;
                    posIndices.pop();
                } else {
                    tamanho -= (preIndices.top().second - iInicial + 1);
                    iInicial = preIndices.top().second + 1;
                    preIndices.pop();
                }
            } else if (!posIndices.empty()) {
                maiorResposta = max(maiorResposta, tamanho*posIndices.top().first);
                tamanho -= (iFinal - posIndices.top().second + 1);
                iFinal = posIndices.top().second - 1;
                posIndices.pop();    
            } else if (!preIndices.empty()) {
                maiorResposta = max(maiorResposta, tamanho*preIndices.top().first);
                tamanho -= (preIndices.top().second - iInicial + 1);
                iInicial = preIndices.top().second + 1;
                preIndices.pop();
            }
        }

        maiorResposta = max(maiorResposta, tamanho*nums[k]);

        return maiorResposta;
    }
};