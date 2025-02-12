class Solution {


public:

    int romanToInt(string s) {
        static const unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            int v = romanMap.at(s[i]);

            if (i + 1 < s.size()) {
                int n = romanMap.at(s[i + 1]);

                if (v < n){
                    result -= v;
                    continue;
                }
            }
            result += v;
        }

        return result;
    }
};