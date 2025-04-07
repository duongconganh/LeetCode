class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n =  nums.size();

        int i = 0;
        int sum = 0;
        for(int &x: nums){
            sum += x;
        }
        if(sum % 2 == 1){
            return false;
        }
        bitset<10001> bit(1);
        for (auto x : nums) {
            bit |= bit << x;
        }
        return bit[sum / 2];
    }
};