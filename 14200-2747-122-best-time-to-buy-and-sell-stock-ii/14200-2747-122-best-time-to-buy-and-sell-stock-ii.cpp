class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int ans = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++ ){
            if(buy > prices[i] && buy == sell){
                buy = prices[i];
                sell = prices[i];
                continue;
            }
            if(prices[i] < sell){
                ans += (sell - buy);
                buy = prices[i];
                sell = prices[i];
            }else{
                sell = prices[i];
                if(i == n - 1){
                    ans += sell - buy;
                }
            }
        }
        
        return ans;
    }
};