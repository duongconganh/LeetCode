class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n == 1){
            return true;
        }
        if(n % 3 == 0 || n % 3 == 1){
            return checkPowersOfThree(n / 3);
        }
        else{
            return false;
        } 
    }
};