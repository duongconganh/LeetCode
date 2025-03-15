class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        int ans = 1;
        dp[0] = nums[0];
        int l, r, mid, temp;
        for(int x: nums){
            if(x > dp[ans - 1]){
                dp[ans ++] = x;
            }else if(x < dp[ans - 1]){
                l = 0;
                r = ans - 1;
                while(l <= r){
                    mid = (l + r) /2;
                    temp = (mid > 0)?dp[mid - 1]:INT_MIN; 
                    if(dp[mid] >= x && temp < x){
                        dp[mid] = x;
                        break;
                    }else if(dp[mid] < x){
                        l = mid + 1;
                    }else if(dp[mid] > x){
                        r = mid - 1;
                    }
                }
            }

        }

        return ans;       
    }
};