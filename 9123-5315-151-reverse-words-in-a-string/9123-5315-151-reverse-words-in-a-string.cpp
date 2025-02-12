class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        s = ' ' + s;
        int len = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i --){
            if(s[i] != ' '){
                len++;
            }else{
                if(len > 0){
                    ans += s.substr(i+1,len) + ' ';
                    len = 0;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};