class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_map<int, array<int,2>> dp;
        int ans = 0;
        for(int x: nums){
            if(dp.find(x) != dp.end()){
                continue;
            }
            if(dp.find(x - 1) == dp.end() && dp.find(x + 1) == dp.end()){
                dp[x][0] = dp[x][1] = x;
 
            }else if(dp.find(x - 1) != dp.end() && dp.find(x + 1) != dp.end()){
               
                dp[x][0] = dp[x - 1][0];
                dp[x][1] = dp[x + 1][1];
                dp[dp[x][0]][1] = dp[x + 1][1];
                dp[dp[x][1]][0] = dp[x - 1][0];
                ans = max(ans,dp[x][1] - dp[x][0]);

            }else if(dp.find(x - 1) == dp.end() && dp.find(x + 1) != dp.end()){
                dp[x][0] = x;
                dp[x][1] = dp[x + 1][1];
                dp[dp[x][1]][0] = x; 
                ans = max(ans,dp[x][1] - dp[x][0]);

            }else{
                dp[x][0] = dp[x-1][0];
                dp[x][1] = x;
                dp[dp[x][0]][1] = x;
                ans = max(ans,dp[x][1] - dp[x][0]); 
            }
        }
        return ans + 1;
    }
};