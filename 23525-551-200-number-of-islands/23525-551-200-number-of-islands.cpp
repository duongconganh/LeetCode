#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    int count;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
public:
    int numIslands(vector<vector<char>>& grid) {
        count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(i , j, grid, n, m);
                    count++;
                }
            }
        }

        return count;
    }
    void dfs(int a, int b, vector<vector<char>>& grid , int n, int m){
        grid[a][b] = '0';
        int x;
        int y;
        for(int k = 0; k < 4; k ++){
            x = a + dx[k];
            y = b + dy[k];
            if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0'){
                continue;
            }
            dfs(x,y,grid,n,m);

        }
    }
};