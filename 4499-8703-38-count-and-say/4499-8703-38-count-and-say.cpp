class Solution {
public:
    string RLE(string &s){
        string ans = "";
        int n =  s.size();
        s += '.';
        int count = 1;
        char x = s[0];
        for(int i = 1;i <= n; ++i){
            if(s[i] != x){
                ans += count + '0';
                ans += x;
                x = s[i];
                count = 1;
                continue;
            }
            count ++;
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1;i < n; ++i){
            ans = RLE(ans);
        }
        return ans;
    }
};