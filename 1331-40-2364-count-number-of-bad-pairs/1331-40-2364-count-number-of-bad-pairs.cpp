class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0;i < nums.size(); i++){
            mp[ i - nums[i]] ++;
            if(mp[ i - nums[i]] > 1){
                ans += (mp[ i - nums[i]] - 1);
            }
        }
        ans = (n * (n - 1)) / 2 - ans;
        return ans;
    }
};