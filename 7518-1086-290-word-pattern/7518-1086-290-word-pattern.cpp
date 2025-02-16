class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s += " ";
        bool ans = true;
        int n = pattern.size();
        int m = s.size();
        unordered_map<char,string> dp;
        vector<string> mp;
        unordered_map<string,int> dps;
        int start = 0;
        for(int i = 0; i < m ; i++){
            if(s[i] == ' '){
                mp.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        if(n != mp.size()){
            return false;
        }

        for(int i = 0;i < n;i ++){
            if(dp.find(pattern[i]) == dp.end()){
                if(dps[mp[i]] == 0){
                    dp[pattern[i]] = mp[i];
                    dps[mp[i]] = 1;
                }else{
                    return false;
                }

            }else{
                if(dp[pattern[i]] != mp[i]){
                    return false;
                }
            } 
        }

        return ans;
    }
};