class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) {
            return false;
        }

        int open = 0, unlocked = 0;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    open++;
                } else {
                    open--; 
                }
            } else {
                unlocked++; 
            }

            if (open < 0) {
                if (unlocked > 0) {
                    unlocked--;
                    open++;
                } else {
                    return false; 
                }
            }
        }

        open = 0;
        unlocked = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == ')') {
                    open++;
                } else {
                    open--; 
                }
            } else {
                unlocked++; 
            }

            if (open < 0) {
                if (unlocked > 0) {
                    unlocked--;
                    open++;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};