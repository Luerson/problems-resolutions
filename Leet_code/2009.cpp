#include <iterator>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() - 1;

        sort(nums.begin(), nums.end());
        auto newEnd = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), newEnd));

        int cont = 0;

        auto lowest =  nums.begin();

        for (auto it = nums.begin(); it != nums.end(); it++) {
            lowest = upper_bound(lowest, nums.end(), *it + n);

            cont = max(cont, (int)distance(it, lowest));
        }

        return n + 1 - cont;
    }
};