class Solution {
public:
    int mod = 1000000007;
    long long helper(long long base, long long expo) {
        long long ans = 1;
        while (expo > 0) {
            if (expo % 2 == 0) {
                base = (base * base) % mod;
                expo = expo / 2;
            } else {
                ans = (ans * base) % mod;
                expo -= 1;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long ans = 1;
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        return (int)((helper(5, even) * helper(4, odd)) % mod);
    }
};