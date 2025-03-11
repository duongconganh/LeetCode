#include <execution>
 
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bigger;
        priority_queue<int> smaller;
        int x, y;
        for(int i = 0; i < capital.size(); i ++){
            x = profits[i];
            y = capital[i];
            if(w >= y){
                smaller.push(x);
            }else{
                bigger.push({y, x});
            }

        }
        while(k && !smaller.empty()){
            int p = smaller.top();
            w += p;
            smaller.pop();
            k--;
            while(k && !bigger.empty()){
                auto x = bigger.top();
                if(w >= x.first){
                    smaller.push(x.second);
                    bigger.pop();
                }else{
                    break;
                }
            }
        }        
        return w;
    }
};