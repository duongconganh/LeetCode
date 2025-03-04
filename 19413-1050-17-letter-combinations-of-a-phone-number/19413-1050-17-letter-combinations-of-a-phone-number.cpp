class Solution {
public:
    vector<string> ans;
    int n;
    vector<string> letterCombinations(string digits) {
        ans.clear();        
        n = digits.size();
        if(n == 0){
            return ans;
        }
        string arr[8] = {{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"qprs"},{"tuv"},{"wxyz"}};
        back(0, digits,"",arr);
        return ans;
    }
    void back(int index, string digits, string s, string arr[]){
        if(index == n){
            ans.push_back(s);
            return;
        }
        string temp;
        for(char x: arr[digits[index] - '0' - 2]){
            temp = x;
            back(index+ 1, digits, s + temp, arr);
        }
        return;
    }
};