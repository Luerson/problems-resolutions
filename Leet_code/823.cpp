class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<long long, long long> possibilidades;
        long long resp = 0;

        for (int i = 0; i < arr.size(); i++) {
            possibilidades[arr[i]] = 1;
        }

        for (auto it = possibilidades.begin(); it != possibilidades.end(); it++) {
            for (auto itJ = possibilidades.begin(); itJ != it && itJ != possibilidades.end(); itJ++) {

                if (it->first % itJ->first == 0 && possibilidades.find(it->first/itJ->first) != possibilidades.end()) {
                    auto itK = possibilidades.find(it->first/itJ->first);
                    it->second += (itJ->second*itK->second)%1000000007;
                }
            }
        }

        for (auto it = possibilidades.begin(); it != possibilidades.end(); it++) {
            resp += it->second;
            resp = resp%1000000007;
        }

        return resp;
    }
};