class Solution {
public:
    int mod = 1000000007;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> map(26, 0);
        for(char x: s){
            map[x - 'a'] ++;
        }
    
        for(int i = 1; i <= t; i ++){
            int temp = map['z' - 'a'];
            for(char x = 'z'; x >= 'b'; x --){
                map[x - 'a'] = map[x - 'a' - 1] % mod;
            }
            map[0] = temp % mod;
            map[1] += (temp % mod);
            map[1] %= mod;

        }
        int ans = 0;
        for(char i = 'a'; i <= 'z';i ++){
            ans += map[i - 'a'];
            ans %= mod;
        }
        return ans;
    }
};