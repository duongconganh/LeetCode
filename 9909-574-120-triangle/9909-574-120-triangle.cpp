class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int l , r;
        int n = triangle.size();
        int m = triangle[n - 1].size();
        for(int i = 1;i < n; i ++){
            for(int j = 0;j < triangle[i].size(); j ++){
                l = (j == 0)? INT_MAX/2:triangle[i-1][j - 1];
                r = (j == triangle[i].size() - 1)? INT_MAX/2:triangle[i - 1][j];
                triangle[i][j] = min(triangle[i][j] + l, triangle[i][j] + r);
            }
        }
        for(int i = 0;i < m; i ++){
            ans = min(ans, triangle[n - 1][i]);
        }
        return ans;
    }
};