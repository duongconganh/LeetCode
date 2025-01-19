class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        if (n < 3 || m < 3) return 0;

        set<pair<int, pair<int, int>>> s;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            s.insert({heightMap[i][0], {i, 0}});
            s.insert({heightMap[i][m - 1], {i, m - 1}});
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 1; j < m - 1; j++) {
            s.insert({heightMap[0][j], {0, j}});
            s.insert({heightMap[n - 1][j], {n - 1, j}});
            visited[0][j] = visited[n - 1][j] = true;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;

        while (!s.empty()) {
            auto [height, pos] = *s.begin();
            s.erase(s.begin());
            int x = pos.first, y = pos.second;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    ans += max(0, height - heightMap[nx][ny]);
                    s.insert({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return ans;
    }
};