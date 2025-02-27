int ans;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0;i < n; i++){
            mp[arr[i]] = i + 1;
        }
        for(int i = 0;i < n - 1;i ++){
            for(int j = i + 1; j < n ;j ++){
                int x = arr[j];
                int y = arr[i] + arr[j];
                int length = 2;
                while(mp.find(y) != mp.end()){
                    int temp = x + y;
                    x = y;
                    y = temp;
                    ans = max(ans,++length);
                }
            }
        } 
        return ans = (ans < 3)?0:ans;
    }

};