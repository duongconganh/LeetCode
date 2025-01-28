class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0;j < n; j ++){
                if(grid[i][j] != 0){
                    int check = dfs(m, n, i, j, grid, grid[i][j]);
                    if(check >= max){
                        max = check;
                    }
                }
            }
        }
        return max;
    }

    int dfs(int m, int n, int a, int b,vector<vector<int>>& grid,int sum){
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        grid[a][b] = 0;
        for(int i = 0; i < 4; i++){
            int x = a + dx[i];
            int y = b + dy[i];
            if(x >= 0 && x < m && y >= 0 &&y < n){
                if(grid[x][y] != 0){
                    sum = dfs(m, n, x, y, grid, sum + grid[x][y]);
                }
            }
        }
        return sum;

    }
};