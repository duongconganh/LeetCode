class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2){
            return n;
        }
        int ans = 0;
        int count = 0;
        double a,b,c;
        for(auto x: points){
            unordered_map<double, int> dp;
            count++;
            int zeros = 1;
            for(int i = count; i < n ;i ++){
                a = x[0] - points[i][0];
                b = x[1] - points[i][1];
                if(b){
                    c = a/b;
                    dp[c] = (dp[c] == 0)? 2:dp[c] + 1;
                    ans = max(ans , dp[c]);
                }else{
                    zeros ++;
                }
            }
            ans = max(ans , zeros);
        }
        return ans;
    }
};