class Solution {
public:
    bool isPalindrome(string s) {
        string r = "";
        string l = "";
        int n = s.size();

        for(int i = 0;i < n; i++){
            if((s[i] >= 'a' && s[i] <= 'z' || isdigit(s[i]) )){
                r += s[i];
            }else if(s[i] >= 'A' && s[i]  <= 'Z'){
                r += (s[i] - 'A' + 'a');
            }
        }
        cout<<r;
        l = r;
        reverse(r.begin(),r.end());
        return r == l;
    }
};