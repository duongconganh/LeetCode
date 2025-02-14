class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty())
            return {};        

        vector<int> ans;
        int n =  s.size();
        int m = words.size();
        int nw = words[0].size();
        string sub = "";
        unordered_map<string,int> check;
        for(string x : words){
            check[x] ++;
        }
        unordered_map<string,int> temp;
        unordered_map<string,int> pre;

        for(int i = 0; i < n - m*nw + 1 ;i ++){
            
            if(pre[s.substr(i,m*nw)] == 1){
                ans.push_back(i);
                continue;
            }else if(pre[s.substr(i,m*nw)] == 2){
                continue;
            }
            temp.clear();        
            for(int j = 0; j < m; j++){
                sub = s.substr(i + j*nw, nw);
                if(check.find(sub) != check.end()){
                    temp[sub] ++;
                }else{
                    pre[s.substr(i,m*nw)] = 2;
                    break;
                }
            }

            if(temp == check){
                ans.push_back(i);
                pre[s.substr(i,m*nw)] = 1;
            }

        }


        return ans;
    }
};