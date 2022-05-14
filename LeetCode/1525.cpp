class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> letters;
        vector<int> leftLetters(s.size());
        for (int i = 0; i < s.size(); i++) {
            letters.insert(s[i]);
            leftLetters[i] = letters.size();
        }
        
        letters.clear();
        int res = 0;
        for (int i = s.size() - 1; i; i--) {
            letters.insert(s[i]);
            res += leftLetters[i - 1] == letters.size();
        }
        
        return res;
    }
};