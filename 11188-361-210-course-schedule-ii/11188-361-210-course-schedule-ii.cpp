class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp(numCourses);
        vector<int> cond(numCourses , 0);
        vector<int> ans;
        for(auto x: prerequisites){
            mp[x[1]].push_back(x[0]);
            cond[x[0]] ++;

        }
        queue<int> q;
        int n = 0;
        for(int i = 0;i < numCourses; i++){
            if(cond[i] == 0){
                if(mp[i].size() != 0){
                    q.push(i);
                }
                ans.push_back(i);
                n ++;
            }
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(int x: mp[temp]){
                cond[x] --;
                if(cond[x] == 0){
                    ans.push_back(x);
                    q.push(x);
                    n++;
                }else if(cond[x] < 0){
                    ans.clear();
                    return ans;
                }
            }

        }
        if(n != numCourses){
            ans.clear();
        }
        return ans;        
    }
};
