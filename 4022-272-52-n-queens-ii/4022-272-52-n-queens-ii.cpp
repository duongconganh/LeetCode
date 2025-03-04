class Solution {
public:
    int ans;
    int totalNQueens(int n) {
        ans = 0;
        vector<int> cl(n, 0);
        vector<int> crossl(n*2,0);
        vector<int> crossr(n*2, 0);
        back(0, n, cl, crossl, crossr);
        return ans;
    }
    void back(int index, int n, vector<int>&cl, vector<int> &crossl, vector<int> &crossr){
        if(index == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; i ++){
            if(cl[i] || crossl[i + index] || crossr[n -index + i]){
                continue;
            }
            cl[i] = 1;
            crossl[i + index] = 1;
            crossr[n - index + i] = 1;
            back(index + 1, n, cl, crossl, crossr);
            cl[i] = 0;
            crossl[i + index] = 0;
            crossr[n -index + i] = 0;
    
        }
        return;
    }
};