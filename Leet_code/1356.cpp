class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> valoresPorBit;
        vector<int> resp;

        for (int i = 0; i < arr.size(); i++) {
            int contBits = 0;
            for (int j = 0; (1<<j) <= arr[i]; j++) {
                if (((1<<j) & (arr[i])) != 0) {
                    contBits++;
                }
            }

            valoresPorBit[contBits].push_back(arr[i]);
        }

        for (auto it = valoresPorBit.begin(); it != valoresPorBit.end(); it++) {
            sort(it->second.begin(), it->second.end());

            for (int i = 0; i < it->second.size(); i++) {
                resp.push_back(it->second[i]);
            }
        }

        return resp;
    }
};