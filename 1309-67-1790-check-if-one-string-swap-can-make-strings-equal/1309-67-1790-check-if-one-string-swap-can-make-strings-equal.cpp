class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> check;
        for(auto x : s1){
            check[x] += 1; 
        }
        int diff = 0;
        for(int x = 0; x < s2.length(); x++){
            if(s1[x] != s2[x]){
                diff ++;
            }
            if(diff > 2){
                return false;
            }
            if(check[s2[x]] == 0){
                return false;
            }else{
                check[s2[x]] -= 1;
            }
        }
        return true;
    }
};