class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";

        vector<string> mp(numRows,"");

        if(numRows == 1){
            return s;
        }
        int n = s.size();
        int pos = 0;
        int status = 1;

        for(int i = 0; i < n ;i++){
            mp[pos] += s[i];
            pos += status;
            if(pos == numRows){
                status = -1;
                pos -= 2;
            }
            if(pos == 0){
                status = 1;
            }
            

        }
        for(int i = 0; i < numRows;i++){
            ans += mp[i];
        }
        return ans;
        
    }
};