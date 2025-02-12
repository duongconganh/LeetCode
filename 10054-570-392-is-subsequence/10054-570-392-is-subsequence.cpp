class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool ans = true;
        int n = s.size();
        int m = t.size();
        if(n == 0){
            return true;
        }
        if(n > m){
            return false;
        }
        for(int i = m - 1; i >= 0; i--){
            if(t[i] == s[n-1]){
                n--;
                s.pop_back();
            }
            if(n == 0){
                return true;
            }
            if(n > i){
                return false;
            }
        }

        return n == 0;
    }
};