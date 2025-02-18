#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        vector<string> ans;
        string s = "/";

        for(int i = 1; i <path.size();i ++){
            if(path[i] == '/'){
                if(s == "/."){
                    s = "/";
                }else if(s == "/.."){
                    if(ans.size() > 0){
                        ans.pop_back();
                    }
                    s = "/";
                }else if(s != "/"){
                    ans.push_back(s);
                    s = "/";
                }

            }else{
                s += path[i];
            }
            
        }
        string a;
        for(string x: ans){
            a += x;
        }

        return a = (ans.size() == 0)?"/":a;
    }
};