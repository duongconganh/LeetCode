class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        while(k>=1)
        {
            int min=nums[0];
            int index=0;
            for(int i=1;i<n;i++)
            {
                if(nums[i]<min)
                {
                    min=nums[i];
                    index=i;
                }
            }
            nums[index]=nums[index]*multiplier;
            k--;
        }
        return nums;
    }
};