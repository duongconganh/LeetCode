class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
 //        vector<int> ball(limit + 1, 0);
        unordered_map <int, int> ball;
        unordered_map <int, int> color;
        for(auto x: queries){
            if(color[x[1]] == 0){
                if(ball[x[0]] == 0 || color[ball[x[0]]] > 1 ){
                    sum += 1;
                }
            }else{
                if(color[ball[x[0]]] == 1 && ball[x[0]] != x[1]){
                    sum -= 1;
                }
            }
            color[ball[x[0]]] -= 1;
            
            ball[x[0] ] = x[1];
            color[x[1]] += 1;
            ans.push_back(sum);
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();