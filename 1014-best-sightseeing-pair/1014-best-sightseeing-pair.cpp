class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        vector<int> i(v.size());
        i[0] = v[0] + 0;
        for(int x = 1; x<v.size();x++)
            i[x] = max(i[x-1], v[x] + x);
        int ans = 0;
        for(int x=1;x<v.size();x++)
            if(ans < v[x] - x + i[x-1]) ans = v[x] - x + i[x-1];
        return ans;
    }
};