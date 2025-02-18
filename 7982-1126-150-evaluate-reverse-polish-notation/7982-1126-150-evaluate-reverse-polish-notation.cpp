class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        stack<int> dp;
        int a,b;
        for(string x: tokens){
            if(x == "*"){
                a = dp.top();
                dp.pop();
                b = dp.top();
                dp.pop();
                dp.push(a * b);
            }else if(x == "+"){
                a = dp.top();
                dp.pop();
                b = dp.top();
                dp.pop();
                dp.push(a + b);
            }else if(x == "-"){
                a = dp.top();
                dp.pop();
                b = dp.top();
                dp.pop();
                dp.push(b - a);
            }else if(x == "/"){
                a = dp.top();
                dp.pop();
                b = dp.top();
                dp.pop();

                dp.push(b / a);
            }else{
                dp.push(stoi(x));
            }
        }
        return dp.top();
        
    }
};