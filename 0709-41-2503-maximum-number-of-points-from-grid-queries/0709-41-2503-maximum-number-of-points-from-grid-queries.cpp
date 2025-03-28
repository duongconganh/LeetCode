class Solution {
public:
    int dir[5] = {0, -1, 0, 1, 0};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(queries.size(), 0);

        auto compare = [&grid](const pair<int, int>& a, const pair<int, int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];
        };

        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> q(compare);
        q.push({0, 0});
        vector<vector<int>> vs(n , vector<int>(m , 0));
        vs[0][0] = 1;
        vector<pair<int, int>> qt(queries.size());
        for (int i = 0; i < queries.size(); i++) qt[i] = {queries[i], i};
        sort(qt.begin(), qt.end());

        for(auto &x: qt){
            while(!q.empty() && grid[q.top().first][q.top().second] < x.first){
                int dx = q.top().first;
                int dy = q.top().second;
                q.pop();
                sum ++;
                for(int i = 0;i < 4; i ++){
                    int a = dx + dir[i];
                    int b = dy + dir[i + 1];
                    if(a >= 0 && b >=0 && a < n && b < m && !vs[a][b]){
                        q.push({a ,b});
                        vs[a][b] = 1;
                    }
                }
            }
            ans[x.second] = sum;
        }

        return ans;
    }
};