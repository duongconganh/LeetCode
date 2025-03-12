class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        bool check = 0;
        for(int i = 0;i < n;i ++){
            int a = (i < 2)?0:nums[i - 2];
            int b = (i < 3)?0:nums[i - 3];
            nums[i] = max(a + nums[i], b + nums[i]);
        }
        return max(nums[n - 1], nums[n - 2]);
    }

};