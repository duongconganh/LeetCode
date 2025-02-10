class Solution {
public:
    string clearDigits(string s) {
//        vector<char> ans;
        string ans = "";
        for(char x: s){
            if(x >= 'a' && x <= 'z'){
                ans += x;
            }else{
                ans.pop_back();
            }
        }
        return ans;
    }
};