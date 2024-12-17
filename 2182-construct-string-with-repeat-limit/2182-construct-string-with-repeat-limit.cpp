class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        
        
        
        vector<int> cnt(26, 0);
        for(auto c : s) cnt[c-'a']++;

        priority_queue<pair<int,int>, vector<pair<int,int>>> maxHeap;
        for(int i=0;i<26;i++)
            if(cnt[i]) maxHeap.push({i, cnt[i]});
    
        vector<char> ans;

        while(maxHeap.size()){
            
            auto [c1, frq1] = maxHeap.top();
            maxHeap.pop();
            

            if( ans.size() == 0 || (ans.back() - 'a' != c1) ){
                // can place the character c1 + 'a' in a row 
                int taken = min(limit, frq1);
                
                for(int i=0;i<taken;i++)
                    ans.push_back(c1+'a');
                
                frq1 -= taken;
                if(frq1)
                    maxHeap.push({c1, frq1});
            }
            else{
                // need to place 1 small character
                if(maxHeap.size() == 0) break;

                auto [c2, frq2] = maxHeap.top();
                maxHeap.pop();

                ans.push_back(c2 + 'a');

                frq2-=1;
                if(frq2)
                    maxHeap.push({c2, frq2});

                maxHeap.push({c1, frq1});
            }
        }

        return string(ans.begin(), ans.end());
    }
};