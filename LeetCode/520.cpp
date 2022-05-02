class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for (char c : word)
            capitalCount += (bool)isupper(c);
        
        return !capitalCount || capitalCount == word.size() ||
               capitalCount == 1 && isupper(word[0]);
    }
};