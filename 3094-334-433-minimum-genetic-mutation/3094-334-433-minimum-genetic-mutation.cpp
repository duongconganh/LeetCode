class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int> mp;
        mp[startGene] = 1;
        int ans = 0;
        int n;
        queue<string> q;
        q.push(startGene);
        while(!q.empty()){
            n = q.size();
            ans ++;
            for(int i = 0; i < n;i ++){
                string temp = q.front();
                q.pop();
                for(string x: bank){
                    if(mp[x] == 0 && check(temp,x)){
                        mp[x] = 1;
                        if(x == endGene){
                            return ans;
                        }
                        q.push(x);
                    }
                }
                
            }

        }

        return -1;
    }
    bool check(string a, string b){
        int sum = 0;
        for(int i = 0;i < a.size(); i++){
            if(a[i] != b[i]){
                sum ++;
            }
        }
        return sum == 1;
    }
};