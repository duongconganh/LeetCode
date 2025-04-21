class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ans = 0;
        int n = differences.size();
        long smallest = 0;
        long biggest = 0;
        long cur = 0;
        for(int i = 0;i < n;i ++){
            cur +=  differences[i];
            smallest = min(smallest, cur);
            biggest = max(biggest, cur);
        }
        long diff = biggest - smallest;
        long dis = upper -lower;

        if(dis >= diff){
            return dis - diff + 1;
        }
        return ans;
    }
};