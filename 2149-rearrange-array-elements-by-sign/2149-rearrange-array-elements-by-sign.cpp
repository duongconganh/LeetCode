class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int negInd=1,posInd=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]<0){ ans[negInd]=nums[i];
           negInd+=2;
           }
           else{ ans[posInd]=nums[i];
           posInd+=2;}
       }
       return ans;
    }
};
static const int Fast__ =[](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();