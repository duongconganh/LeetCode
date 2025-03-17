class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        vector<int> mp(501, 0);
        int n = nums.size();
        for(int &x : nums){

            if(mp[x] % 2 == 0){
                odd ++;
                mp[x] = 1;
            }else{
                even ++;
                mp[x] = 0;               
            }

        }
        return odd == even;
    }
};