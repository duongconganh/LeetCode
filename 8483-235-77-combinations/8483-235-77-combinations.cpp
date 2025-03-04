#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> save(k,0);
        back(0, 0, n, k, save, ans);
        return ans;
    }
    void back(int index,int temp,int n,int k, vector<int>& save,vector<vector<int>>& ans){
        if(index == k){
            ans.push_back(save);
            return;
        }
        for(int i = temp + 1; i <= n;i ++){
            save[index] = i;
            back(index + 1, i , n, k, save, ans);
        }
    }
};