class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = 0;
        int ans = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++ ){
            if(buy > prices[i]){
                buy = prices[i];
                continue;
            }
            sell = prices[i] - buy;
            if(ans < sell){
                ans = sell;
            }
        }
        return ans;
        
    }
};