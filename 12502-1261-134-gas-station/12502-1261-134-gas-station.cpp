class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int n =  gas.size();
        int sum = 0;
        vector<int> dp;
        for(int i = 0; i < n; i++){
            int s = gas[i] - cost[i];
            sum += s;
            dp.push_back(s);
        }
        if(sum < 0){
            return -1;
        }
        for(int i = 0;i < n ;i ++){
            if(dp[i] > 0 && dp[(n + i - 1) % n] < 0){
                int count = 0;
                for(int j = 0; j < n;j ++){
                    count += dp[(n + i + j) % n];
                    if(count < 0){
                        break;
                    }
                }
                if(count >=0){
                   return i;
                }

            }
        }
        return ans;
    }
};