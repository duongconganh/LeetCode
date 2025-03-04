class Solution {
public:
    int n;
    int t;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        n = candidates.size();
        t = target;
        sort(candidates.begin(),candidates.end());
        vector<int> save;
        back(0, candidates, save, ans, 0);
        return ans;
    }
    void back(int index ,vector<int>& candidates, vector<int> &save, vector<vector<int>> &ans, int sum){

        if(sum == t){
            ans.push_back(save);
            return;
        }
        for(int i = index; i < n; i ++){
            if(sum + candidates[i] > t){
                return;
            }
            save.push_back(candidates[i]);
            back(i, candidates, save, ans, sum + candidates[i]);
            save.pop_back();
        }
        return;
    }
};