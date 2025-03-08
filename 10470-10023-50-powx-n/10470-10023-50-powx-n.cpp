class Solution {
public:
    double myPow(double x, double n) {
        if(x == 1 || x == - 1){
            int a = n;
            return (a % 2 == 1)?x:1;
        }
        if(n == 0){
            return 1;
        }
        double ans = (n < 0)? 1/x:x;
        double index = 1;
        while(index * 2 <= abs(n)){
            ans = ans* ans;
            index *= 2;
        }
        n = (n < 0)? n + index: n - index ;
        return ans * myPow(x, n);
    }
};