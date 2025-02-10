class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums1 = nums;
        for(int i = 0 ; i < n; i ++){
            nums[(i + k) % n] = nums1[i];
        }
        
    }
};