class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2 , -1);
        int n = nums.size();
        if(n < 1){
            return ans;
        }
        int l = 0;
        int r = n - 1;
        int mid;
        int start = 0;
        int end = n - 1;
        if(nums[start] != target){
            while(l <= r){
                mid = (l + r)/2;
                if(nums[mid] == target && nums[mid - 1] < target){
                    start = mid;
                    break;
                }else if(nums[mid] < target){
                    l = mid + 1;
                }else if(nums[mid] >= target){
                    r = mid - 1;
                }
            }
        }
        l = start;
        r = n - 1;
        if(nums[end] != target){
            while(l <= r){
                mid = (l + r)/2;
                if(nums[mid] == target && nums[mid + 1] > target){
                    end = mid;
                    break;
                }else if(nums[mid] <= target){
                    l = mid + 1;
                }else if(nums[mid] > target){
                    r = mid - 1;
                }
            }
        }
        if(nums[start] != target || nums[end] != target){
            return ans;
        }
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
};