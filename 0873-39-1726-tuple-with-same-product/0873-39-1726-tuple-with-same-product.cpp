class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int sum = 0;
        int firt = 0;
        int last = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < last - 3; i ++){

            for(int j = last - 1; j > i + 2 ; j--){
                int mul = nums[i] * nums[j];
                sum += 8 * check(nums, i + 1, j - 1, mul);
            } 
        }

        return sum;
    }

    int check(vector<int>& nums, int start,int end ,int mul){
        int sum = 0;
        for(int i = start; i < end; i ++){
            for(int j = end; j > i; j--){
                int checkmul = nums[i] * nums[j];
                if(checkmul == mul){
                    sum ++;
                    end = j - 1;
                    break;
                }else if(checkmul < mul){
                    end = j;
                    break;
                }
            }
        }
        return sum;
    }
};