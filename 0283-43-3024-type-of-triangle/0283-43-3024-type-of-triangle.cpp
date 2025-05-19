class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[2], b = nums[1], c = nums[0];
        if(a < b + c){
            if(a == b && b == c){
                return "equilateral";
            }else if(a == b || b == c || a == c){
                return "isosceles";
            }else{
                return "scalene";
            }
        }else{
            return "none";
        }

    }
};