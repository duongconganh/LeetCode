class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans = false;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size();i ++){

            if(mp[nums[i]] == 0){
                mp[nums[i]] = i + 1;
            }else{
                if(i - mp[nums[i]] < k){
                    return true;
                }else{
                    mp[nums[i]] = i + 1;
                }
            }

        }
        return ans;
    }
};