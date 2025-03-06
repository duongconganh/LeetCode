class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vs(n*n, 0);
        vector<int> ans(2,0);
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                if(vs[grid[i][j] - 1] == 1){
                    ans[0] =grid[i][j];
                }
                vs[grid[i][j] - 1] ++;
            }
        }
        for(int i = 0;i < n*n ;i ++){
            if(vs[i] == 0){
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};