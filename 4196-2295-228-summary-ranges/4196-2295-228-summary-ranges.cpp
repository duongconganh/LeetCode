class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return {};
        }
        vector<string> ans;
        ans.push_back(to_string(nums[0]));
        int index = 0;
        int count = 0;
        for(int i = 1;i < n; i++){
            if(nums[i] == nums[i - 1] + 1){
                count ++;
            }else{
                if(count == 0){
                    index++;
                    ans.push_back(to_string(nums[i]));                    
                }else{
                    ans[index] += "->";
                    ans[index] += to_string(nums[i - 1]);
                    index++;
                    ans.push_back(to_string(nums[i]));
                    count = 0;
                }

            }
        }
        if(count != 0){
            ans[index] += "->";
             ans[index] += to_string(nums[n - 1]);               
        }
        return ans;
    }
};