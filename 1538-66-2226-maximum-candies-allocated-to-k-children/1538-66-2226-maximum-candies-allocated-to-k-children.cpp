class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int n = candies.size();
        long long sum = accumulate(candies.begin(), candies.end(), 0.0);
        int mid;
        int low = 1;
        int hight = sum / k;
        while(low <= hight){
            mid = (low + hight) / 2;
            if(checksum(candies, mid, k)){
                ans = mid;
                low = mid + 1;
            }else{
                hight = mid - 1;
            }
        }
        return ans;
    }
    bool checksum(vector<int>& candies,int &n, long long &k){
        long long sum = 0;
        for(int i = candies.size() - 1; i >= 0;i --){
            sum += candies[i] / n;
        }
        return sum >= k;
    }
};