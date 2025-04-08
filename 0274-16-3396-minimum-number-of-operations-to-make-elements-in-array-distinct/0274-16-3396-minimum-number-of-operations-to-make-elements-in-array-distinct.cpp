class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        vector<bool> mp(101, 0);
        int n =  nums.size();
        int first = 0;
        for(int i = n - 1;i >= 0;i --){
            if(mp[nums[i]]){
                ans = i + 1;
                return (ans % 3 == 0)?(ans / 3):(ans/3 + 1);
            }
            mp[nums[i]] = true;
        }
        return 0;
    }
};