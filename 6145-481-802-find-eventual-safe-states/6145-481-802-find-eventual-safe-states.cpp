class Solution {
public:
bool dfs(vector<vector<int>>&graph , int i,vector<int>&visit,vector<int>&node){
    if(graph[i].size() == 0) {
        node[i] = 1;
        return true;
    }
    if(visit[i]) return node[i];//take care of loop
    visit[i] = 1;
    bool a = true;
    for(auto nei : graph[i]){
        a &= dfs(graph,nei,visit,node); // take care of the unsafe node cases
    }
    node[i] = a;
    return a;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
     vector<int>visit(n,0);
     vector<int>v;
     vector<int>node(n,0);
     for(int i=0;i<n;i++){
       bool ans = dfs(graph,i,visit,node);
       if(ans) v.push_back(i);
     }
     return v;
    }
};