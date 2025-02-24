class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;
        for(int i = digits.size() - 1;i >=0;i --){
            plus = (digits[i] + 1)/10;
            digits[i] = (digits[i] + 1)%10;
            if(plus == 0){
                break;
            }
        }
        if(plus == 1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};