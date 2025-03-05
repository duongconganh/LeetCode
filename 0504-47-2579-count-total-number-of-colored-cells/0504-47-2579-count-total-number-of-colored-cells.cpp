class Solution {
public:
    long long coloredCells(long long n) {
        return 1 + 2*n*(n - 1);
    }
};