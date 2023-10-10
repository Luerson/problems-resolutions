class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);

        for (int start = 0, end = length-1, i = (end + start)/2; length > 0;) {
            if (end - start == 0 && nums[i] != target) {
                break;
            } else if (target < nums[i] || (i > 0 && nums[i-1] == target)) {
                end = max(i-1, 0);
                i = (end+start)/2;
            } else if (target > nums[i]) {
                start = min(length-1, i+1);
                i = (end+start)/2;
            } else if (nums[i] == target){
                result[0] = i;
                break;
            }
        }

        for (int start = 0, end = length-1, i = (end + start)/2; length > 0;) {
            if (end - start == 0 && nums[i] != target) {
                break;
            } else if (target < nums[i]) {
                end = max(i-1, 0);
                i = (end+start)/2;
            } else if (target > nums[i] || (i < length-1 && nums[i+1] == target)) {
                start = min(length-1, i+1);
                i = (end+start)/2;
            } else {
                result[1] = i;
                break;
            }
        }

        return result;
    }
};