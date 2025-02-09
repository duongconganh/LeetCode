class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0;i < n; i++){
            ans += (++mp[ i - nums[i]] - 1);
        }
        return (n * (n - 1)) / 2 - ans;;
    }
};