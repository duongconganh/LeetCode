class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        int n =  nums.size()/2;
        for(auto x : nums){
            mp[x] ++;
            if( mp[x] > n){
                return x;
            }
        }
        return ans;
    }
};