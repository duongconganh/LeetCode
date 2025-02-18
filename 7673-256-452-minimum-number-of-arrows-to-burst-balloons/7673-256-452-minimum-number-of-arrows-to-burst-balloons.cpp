#include <execution>
 
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        int n = points.size();
        if(n == 1){
            return 1;
        }
        sort(points.begin(),points.end());


        for(int i = 1; i < n;i ++){
            if(points[i - 1][1] >= points[i][0]){
                points[i][1] = min(points[i][1],points[i - 1][1] );
            }else{
                ans++;
            }
        }
        

        return ans;
    }
        

};