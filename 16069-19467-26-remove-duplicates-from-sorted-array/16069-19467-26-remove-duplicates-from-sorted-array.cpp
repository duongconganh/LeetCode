class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        int check = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            if(check != nums[i]){
                nums[ans++] = nums[i];
                check = nums[i];
            }
        }
        return ans;
    }
};