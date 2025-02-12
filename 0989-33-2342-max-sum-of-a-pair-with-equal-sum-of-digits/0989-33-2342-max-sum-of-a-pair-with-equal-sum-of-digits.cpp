class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int m = -1;
        unordered_map<int,int> dp;
        int equal = 0;
        int a = 0;

        for(auto x: nums){
            a = check(x);
            if(dp[a] > 0){
                m =  max(m , dp[a] + x);
                if(dp[a] < x){
                    dp[a] = x;
                }
            }else{
                dp[a] = x;
            }
        }
        return m;
        
    }
    int check(int x){
        int equal = 0;
        while(x != 0){
            equal += (x % 10);
            x = x / 10;
        }
        return equal;
    }
};