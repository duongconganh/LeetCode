class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // vector<int> mp(1001, 0);
        unordered_map<int, int> mp;
        int ans = 0;
        for(int &x: answers){
            mp[x] ++;
        }
        for(auto &x: mp){
            int a = x.second;
            int b = x.first;
            ans += ceil(((double)a/(b + 1))) * (b + 1);
        }
        return ans;
    }
};