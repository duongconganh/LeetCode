class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long ans = 0;
        vector<long long> dp(n + 1, 0);
        int pre  = 0;
        for(int i = n - 1;i >= 0 ;i --){
            pre = i + questions[i][1] + 1;
            if(pre <= n - 1){
                dp[i] = max(dp[i + 1], dp[pre] + questions[i][0]);
            }else{
                dp[i] = max(dp[i + 1], questions[i][0] + dp[n]);
            }
        }        
        return dp[0];
    }
};