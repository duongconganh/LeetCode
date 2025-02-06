class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int sum = 0;
        int firt = 0;
        int last = nums.size();
        unordered_map<int, int> mul;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < last - 1 ; i ++){
            for(int j = i+ 1; j < last ; j++){
                mul[nums[i] * nums[j]] += 1;
                if(mul[nums[i] * nums[j]] > 1){
                    sum += 8 * (mul[nums[i] * nums[j]] - 1 );
                }
            } 
        }

        return sum;
    }


};