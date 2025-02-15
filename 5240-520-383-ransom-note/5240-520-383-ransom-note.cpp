class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        vector<int> dp(128,0);
        for(auto x: ransomNote){
            dp[x] ++;

        }
        int count = 0;
        for(auto x: magazine){
            if(dp[x] > 0){
                dp[x] --;
                count++;
            }
        }
        return count == n;
    }
};