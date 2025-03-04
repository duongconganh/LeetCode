class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        n = nums.size();
        vector<int> save(n, 0);
        back(0, nums, save, ans);
        return ans;
    }
    void back(int index,vector<int>& nums, vector<int> &save, vector<vector<int>> &ans){
        if(index == n){
            ans.push_back(save);
            return;
        }
        int temp;
        for(int i = 0; i < n; i ++){
            if(nums[i] != -99){
                temp = nums[i];
                nums[i] = -99;
                save[index] = temp;
                back(index + 1,nums, save, ans);
                nums[i] = temp;
            }
        }
    }
};