class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ans = 0;
        int zeros = 0;
        int n = nums.size();
        for(int x: nums){
            if(x < 0){
                ans++;
            }else if(x == 0){
                zeros ++;
            }
        }
        return max(ans, - zeros + n - ans);
    }
};