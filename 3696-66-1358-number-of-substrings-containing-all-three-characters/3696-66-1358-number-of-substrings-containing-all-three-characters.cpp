class Solution {
public:
    int numberOfSubstrings(string s) {
        int mp[3] = {0};
        int size = 0;
        int cnt = 0;
        int ans = 0;
        for(char x : s){
            if(x == 'a' || x == 'b' || x == 'c'){
                size = ( !mp[x - 'a'])?size + 1: size;
                mp[x - 'a'] ++;
            }
            while(size == 3){
                mp[s[cnt] - 'a'] --;
                if(mp[s[cnt] - 'a'] == 0){
                    size --;
                }
                cnt++;
            }
            ans += cnt;
        }
        return ans;
    }
};