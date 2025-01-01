class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeroes = 0, score = 0;

        for (char c : s) {
            if (c == '1') ones++;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                zeroes++;
            } else {
                ones--;
            }
            score = max(score, zeroes + ones);
        }

        return score;
    }
};