class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int cnt = 0;
        int index = 0;
        for(int &x : nums){
            sum += x;
            cnt ++;
            while(sum * cnt >= k){
                sum -= nums[index ++];
                cnt --;
            }
            ans += cnt;
        }
        return ans;
    }
};