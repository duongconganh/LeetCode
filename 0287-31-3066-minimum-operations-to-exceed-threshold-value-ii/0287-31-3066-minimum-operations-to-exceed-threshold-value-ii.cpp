class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
//        multiset<long long> dp; 
        priority_queue<long, vector<long>,greater<long>> dp;
//        priority_queue<int> dp;
        int ans = 0;
        for(auto x: nums){
            dp.push(x);
        }
        long long x,y;
        long long add;
        while(dp.top() < k && dp.size() >= 2){
            x = dp.top();
            dp.pop();
            y = dp.top();
            dp.pop();
            add = min(x,y)*2 + max(x,y);
            dp.push(add);
            ans++;

        }

        return ans;
    }
};