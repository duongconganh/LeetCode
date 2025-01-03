class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot = 0, left = 0;
        int ans = 0;

        for (int num : nums) {
            tot += num;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            left += nums[i];
            if (left >= tot - left) {
                ++ans;
            }
        }

        return ans;
    }
};