class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unordered_map<int,int> dp;
        for(int i = 0; i < numbers.size(); i++){
            
            if(dp[ target - numbers[i]] != 0 && i + 1 != dp[ target - numbers[i]] ){
                ans.push_back(dp[ target - numbers[i]]);
                ans.push_back(i + 1);
                break;
            }
            dp[numbers[i]] = i + 1;
        }
        return ans;
    }
};