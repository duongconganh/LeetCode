class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int top,left;
        for(int i = 1; i < m; i ++){
            grid[0][i] += grid[0][i - 1];
        }
        for(int i = 1;i < n;i ++){
            for(int j = 0; j < m; j ++){
                top = (i == 0)?999999:grid[i - 1][j];
                left = (j == 0)?999999: grid[i][j - 1];
                grid[i][j] = min(grid[i][j] + top, grid[i][j] + left);
            }
        }
        return grid[n - 1][m - 1];
    }
};