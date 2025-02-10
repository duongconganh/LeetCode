class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        for(int i = 0; i < m; i++){
            nums.push_back(nums1[i]);
        }
        int a = 0;
        int b = 0;
        for(int i = 0; i < m + n;i++){
            if(a < m && b <n){
                if(nums[a] < nums2[b]){
                    nums1[i] = nums[a++];
                }else{
                    nums1[i] = nums2[b++];
                }
            }else if(a == m){
                nums1[i] = nums2[b++];
            }else{
                nums1[i] = nums[a++];
            }
        }
    }
};