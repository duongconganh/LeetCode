class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        string ans = "";
        int res = 0;
        int x,y,temp;
        while(n > 0 || m > 0 || res){
            x = (n < 1)? 0 : a[n - 1] - '0';
            y = (m < 1)? 0 : b[m - 1] - '0';

            temp = ((x ^ y) ^ res);
            
            res = ((x && y)|| (x ^ y) && res) ? 1: 0;
            ans += temp + '0';
            n --;
            m --;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};