class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size(), c = isWater[0].size();
        vector<vector<int>> heights(r, vector<int>(c, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isWater[i][j]) {
                    q.emplace(i, j);
                    heights[i][j] = 0;
                }
            }
        }

        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c && heights[nx][ny] == -1) {
                    heights[nx][ny] = heights[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }

        return heights;
    }
};