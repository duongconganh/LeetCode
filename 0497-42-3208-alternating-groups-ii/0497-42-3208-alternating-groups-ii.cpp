#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int check = 0;
        int pre = -1;
        for(int i = 0;i < n + k - 1;i ++){
            if(colors[i % n] == pre){
                check = 0;
            }
            check ++; 
            ans = (check >= k)?ans + 1:ans;
            pre = colors[i % n];
        }
        return ans;
    }
};