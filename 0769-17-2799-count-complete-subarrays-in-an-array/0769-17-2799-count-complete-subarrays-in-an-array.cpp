class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       int ans = 0;
       unordered_map<int,int> map;
       int n = nums.size();
       for(int &x: nums){
            map[x] ++;
       }
       int cnt = map.size();
       vector<int> mp(2001, 0);
       int check = 0;
       int x = 0;
       int pre = 0;

       for(int i = 0;i < n;i ++){
            x = nums[i];
            if(mp[x] == 0){
                check ++;
            }
            mp[x] ++;
            while(mp[nums[pre]] > 1){
                mp[nums[pre ++]] --;
            }
            if(check == cnt){
                ans += (pre + 1);
            }
       }
       return ans; 
    }
};