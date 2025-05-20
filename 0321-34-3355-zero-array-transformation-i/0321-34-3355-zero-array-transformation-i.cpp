class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> map(n + 1);
        for(auto &x: queries){
            map[x[0]] --;
            map[x[1] + 1] ++;
        }      
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += map[i];
            if(nums[i] > -sum){
                return false;
            }
        }
        return true;
    }
};