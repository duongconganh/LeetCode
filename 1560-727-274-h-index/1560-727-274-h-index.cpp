class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        sort(citations.begin(),citations.end());
        int n = citations.size();
        for(int i = 0; i <n; i ++){
            if( citations[i] > 0){
                if(n - i >= citations[i]){
                    h = citations[i];
                }else{
                    if(h < n - i){
                        h = n - i;
                    }
                }
            }
        }
        return h;
    }
};