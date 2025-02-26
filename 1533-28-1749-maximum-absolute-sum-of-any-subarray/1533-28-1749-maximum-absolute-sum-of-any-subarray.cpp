class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int neg = 0;
        int pos = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(sum < 0 ){
                ans = max(ans, abs(sum - pos));
                neg = min(neg,sum);
                
            }else{
                ans = max(ans, sum - neg);
                pos = max(pos,sum);
            }
        }

        return ans;
    }
};