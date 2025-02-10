class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        int check = nums[0];
        int dp = 1;
        for(int i = 1 ; i < nums.size(); i++){
            if(check != nums[i]){
                nums[ans++] = nums[i];
                check = nums[i];
                dp = 1;
            }else if(dp < 2){
                nums[ans++] = nums[i];
                dp ++;
            }
        }
        return ans;
    }
};