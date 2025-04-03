class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        long long  sub = nums[0];
        long long minus = nums[1];
        long long a = nums[0] - nums[1];
        for(int i = 2;i < n; i ++){
            ans = max(ans, a * nums[i]);
            sub = max(sub , minus);
            minus = nums[i];
            a = max(a, sub - minus);
            
        }
        return ans;
    }
};