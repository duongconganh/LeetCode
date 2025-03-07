class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while(l <= r){
            mid = (l + r) / 2;
            int m = min(nums[l],min(nums[r], nums[mid]));
            if(m == nums[l]){
                return m;
            }else if(m == nums[mid]){
                r = mid;
            }else if(m == nums[r]){
                l = mid + 1;
            }
        }
        return 1;
    }
};