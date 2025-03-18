class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int temp = 1;
        int index = 0;
        int bit = nums[0]; 
        int a,b;
        for(int i = 1;i < n; i++){
            a = nums[i] ;
            b = nums[i - 1]; 
            if((a & b) != 0){
                ans = max(temp ,ans);
                bit = a;
                index = i;
                temp = 1;;
            }else{
                if((bit ^ a) == bit + a){
                    temp ++;
                    bit += a;
                }else{
                    ans = max(temp ++, ans);
                    while( bit & a ){
                        bit ^= nums[index ++];
                        temp--;
                    }
                    bit ^= a;
                }
            }
        }
        ans = max(ans , temp);
        return  ans;
    }
};