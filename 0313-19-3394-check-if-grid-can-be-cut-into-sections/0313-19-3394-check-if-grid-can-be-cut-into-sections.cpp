class Solution {
public:
    bool cutgrid(vector<pair<int,int>> &p){
        int a,b;
        sort(p.begin(), p.end());
        int check = p[0].second;
        int cut = 0;
        for(auto &x: p){
            a = x.first;
            b = x.second;
            if(check <= a){
                cut ++;
            }
            check = max(check , b);
            if(cut == 2){
                return true;
            }
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> vertical;
        vector<pair<int,int>> horizontal;
        for(auto &x: rectangles){
            horizontal.push_back({x[0],x[2]});
            vertical .push_back({x[1],x[3]});
        }
        if(cutgrid(vertical) || cutgrid(horizontal)){
            return true;
        }
        return false;
    }
};