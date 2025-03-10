
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while(left != right){
            cnt += 1;
            left >>= 1;
            right >>= 1;
        }
        return left<<cnt;
    }
};