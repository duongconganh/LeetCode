class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        int m = 1;
        int ans = 0;
        for(int i = 1; i < n;i ++){
            if(dp[i - 1] <  i){
                if(s[i] == s[i - dp[i - 1] - 1]){
                    dp[i] = dp[i - 1] + 2;
                    if(m < dp[i]){
                        m = dp[i];
                        ans = i - dp[i] + 1;
                    }
                    continue;
                }
            }
            dp[i] = check(s , i, dp[i - 1] + 1);
            if(m < dp[i]){
                m = dp[i];
                ans = i - dp[i] + 1;
            }     
        }
        return s.substr(ans, m);
    }
    int check(string &s, int index, int length){

        int l,r;
        for(int i = length;i >= 1;i --){
            bool c = true;
            l = index - i + 1;
            r = index;
            while(l <= r){
                if(s[l] == s[r]){
                    l ++;
                    r--;
                }else{
                    c = false;
                    break;
                }
            }
            if(c){
                return i;
            }
        }
        return 1;
    }
 
};