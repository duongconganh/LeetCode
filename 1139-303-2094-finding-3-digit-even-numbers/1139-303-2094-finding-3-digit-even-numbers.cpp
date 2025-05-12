class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> map(10, 0);
        for(int digit:digits){
            map[digit] += 1;
        }
        for(int i = 0; i < 9;i += 2){
            if(map[i] == 0){
                continue;
            }
            map[i] --;
            for(int j = 0;j < 10; j ++){
                if(map[j] == 0){
                    continue;
                }
                map[j] --;
                for(int k = 1;k < 10;k ++){
                    if(map[k] != 0){
                        ans.push_back(k* 100 + j * 10 + i);
                    }
                }
                map[j] ++;
            }
            map[i] ++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};