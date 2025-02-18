class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        pattern += 'I';
        int n = pattern.size();
        int start = 2;
        string s= "1";

        for(int i = 0; i < n;i ++){
            if(pattern[i] == 'I'){
                ans += s;
                s = char('0' + start);

            }else{
                s = char('0' + start) + s;
            }
            start ++;

         }
 
        return ans ;
    }
};