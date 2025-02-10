class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        if(nums.size() == 1){
            return 0;
        }
        if(nums[0] >= n - 1){
            return 1;
        }
        int canjump = nums[0];
        int max =  0;
        int index = 0;
        for(int i = 1;i < n - 1;i++){
            canjump --;
            if(canjump == -1){
                return 0;
            }
            if(i + nums[i] > max){
                max = i + nums[i];
                index = i;
            }
            if(canjump == 0){
                canjump = max - i;
                ans++;
               if(max >= n - 1){
  //                  return max;
                    break;
                }
                
            }

        }

        return ans;
        
    }
        
};
