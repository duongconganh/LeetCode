class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);

        for (auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int>BobPath(n, -1);
        vector<int> path;
        function<bool(int, int)> BobFill = [&](int node, int parent){
            if (node == 0)
                return true;

            for (int nei : graph[node]){
                if (nei != parent){
                    path.push_back(node);
                    if (BobFill(nei, node))
                        return true;
                    path.pop_back();
                }
            }
            return false;
        };
        BobFill(bob, -1);
        for (int i = 0; i < path.size(); i++){
            BobPath[path[i]] = i;
        }
        function<int(int, int, int, int)> Alice = [&](int node, int parent, int cur, int time){
            if (BobPath[node] == -1 || BobPath[node] > time){
                cur += amount[node];
            } else if (BobPath[node] == time){
                cur += amount[node] / 2;
            }
            if (graph[node].size() == 1 && node != 0)
                return cur;
            int maxScore = INT_MIN;
            for (int nei : graph[node]){
                if (nei != parent){
                    maxScore = max(maxScore, Alice(nei, node, cur, time + 1));
                }
            }
            return maxScore;
        };
        return Alice(0, -1, 0, 0);
    }
};
