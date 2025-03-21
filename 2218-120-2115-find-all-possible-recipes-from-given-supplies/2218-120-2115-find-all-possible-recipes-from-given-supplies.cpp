class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_map<string ,int> mp;
        unordered_map<string ,vector<string>> food;
        int i = 0;
        for(const string &x : recipes){
            mp[x] = ingredients[i].size();       
            for(const string &y: ingredients[i]){
                food[y].push_back(x);
            }
            ++i;
        }
        int n = supplies.size();
        for(i = 0;i < n;i ++){
            for(const string &y : food[supplies[i]]){
                if(!(--mp[y])){
                    supplies.push_back(y);
                    ans.push_back(y);
                    n ++;
                }
            }
        }
        return ans;
    }
};