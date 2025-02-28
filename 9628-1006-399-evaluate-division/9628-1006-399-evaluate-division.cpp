class Solution {
        unordered_map<string, vector<string>> mp;
        unordered_map<string, double> dot;
        unordered_map<string ,int> vs;
        double result;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        mp.clear();
        dot.clear();
        for(int i = 0;i < equations.size(); i++){
            mp[equations[i][0]].push_back(equations[i][1]);
            mp[equations[i][1]].push_back(equations[i][0]);
            dot[equations[i][0] + "/" + equations[i][1]] = values[i];
            dot[equations[i][1] + "/" + equations[i][0]] = 1/values[i];
        }
        for(auto x: queries){
            if(dot.find(x[0] + "/" + x[1]) != dot.end()){
                ans.push_back(dot[x[0] + "/" + x[1]]);
            }else{

                if(x[0] == x[1] && mp.find(x[0]) != mp.end()){
                    ans.push_back(1);
                    cout<<x[0];
                    continue;
                }
                vs[x[0]] = 1;
                result = -1;
                cout<<x[0]<<" "<<x[1]<<" ";
                checkdot(x[0], x[1], 1);
                vs.clear();
                ans.push_back(result);
            }
        }
        return ans;
    }
    void checkdot(string a, string b, double ans){
        string s = a + "/";

        if(mp.find(a) == mp.end()){
            return;
        }
        for(string x: mp[a]){
            if(vs[x] == 0){
                vs[x] = 1;
                if(x == b){
                    result = ans*dot[s + x];
                    break;
                }
                checkdot(x, b, ans * dot[s + x]);
                
            }
        }

        return;
    }
};