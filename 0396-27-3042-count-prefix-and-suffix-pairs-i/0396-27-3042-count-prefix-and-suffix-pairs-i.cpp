class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0; 

        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i].size() > words[j].size()) {
                    continue;
                }

                bool isPrefix = words[j].find(words[i]) == 0;

                bool isSuffix = words[j].rfind(words[i]) == words[j].size() - words[i].size();

                if (isPrefix && isSuffix) {
                    count++;
                }
            }
        }
        return count;
    }
};