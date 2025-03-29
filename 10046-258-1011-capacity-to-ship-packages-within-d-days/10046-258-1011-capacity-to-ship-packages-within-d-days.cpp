class Solution {
public:
    bool check(vector<int>& weights, int wei, int days){
        int ans = 0;
        int temp = 0;
        for(int &x:weights){
            if(temp >= x){
                temp -= x;
            }else{
                ans ++;
                temp = wei - x;
            }
        }
        return ans <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int l = *max_element(weights.begin(), weights.end());
        int r = l *(weights.size()/days  + 1);
        int ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(check(weights, mid, days)){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};