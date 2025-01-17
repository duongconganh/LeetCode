class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int totalXOR = 0;
        for (const int num : derived) {
            totalXOR ^= num;
        }
        return totalXOR == 0;
    }
};