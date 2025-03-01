class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int check = 0;
        for(int x: nums){
            if(x == 0){
                check = 0;
                continue;
            }
            if(check != 0 && check == x){
                ans.back() = check * 2;
                check = 0;
                continue;
            }
            ans.push_back(x);
            check = x;
        }
        vector<int> zeros(n - ans.size(),0);
        ans.insert(ans.end(), zeros.begin(), zeros.end());
        return ans;
    }
};