class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor_nums2=0;
        int xor_nums1=0;
        for(int i=0;i<nums1.size();i++){
            xor_nums1^=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            xor_nums2^=nums2[i];
        }

        if(nums2.size()%2==0){
            if(nums1.size()%2!=0){
                return xor_nums2;
            }
            else{
                return 0;
            }
        }
        else{
            if(nums1.size()%2==0){
                return xor_nums1;
            }
            else{
                return xor_nums1^xor_nums2;
            }
        }
    }
};