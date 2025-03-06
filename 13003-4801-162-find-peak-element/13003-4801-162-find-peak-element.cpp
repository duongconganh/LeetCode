class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans;
        int a,b;
        while(l <= r){
            ans = (l + r)/2;
            a = (ans > 0)?nums[ans - 1]:INT_MIN;
            b = (ans < n - 1)?nums[ans + 1]:INT_MIN;;
            if(nums[ans] > a && nums[ans] > b ){
                return ans;
            }else if(nums[ans] <= b){
                l = ans + 1;
            }else if(nums[ans] <= a){
                r = ans - 1;
            }
            
        }
        return ans;

    }
};