class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        int n = a.size();
        
        vector<int> res;
        res = a;
        for(int i=0;i<n;i++)
        {
            for(int j= i+1;j<n;j++)
            {
                if(a[i]>=a[j]){
                    res[i] = a[i]-a[j];
                    break;
                }
            }
        }
        
        return res;
    }
};