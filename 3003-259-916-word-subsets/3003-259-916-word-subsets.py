class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        need = Counter()
        for word in words2:
            need |= Counter(word)  # We're merging all the characters we need 

        # Now, let's check each word in words1 to see if it's universal 
        result = []
        for word in words1:
        # Count the characters in each word from words1 and compare with 'need' 
            if not (need - Counter(word)):  # if word has all the characters from need 
                result.append(word)

        return result