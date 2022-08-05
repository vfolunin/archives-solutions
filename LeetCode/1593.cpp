class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
    void uniqueSplit(string &s, int mask, int &res) {
        int wordCount = ones(mask) + 1;
        if (wordCount <= res)
            return;
        
        unordered_set<string> words;
        string word;
        
        for (int i = 0; i < s.size(); i++) {
            word += s[i];
            if (i + 1 == s.size() || (mask & (1 << i))) {
                if (words.count(word))
                    return;            
                words.insert(word);
                word.clear();
            }
        }
        
        res = max(res, wordCount);
    }
    
public:
    int maxUniqueSplit(string &s) {
        int maxMask = 1 << (s.size() - 1), res = 1;
        for (int mask = 0; mask < maxMask; mask++)
            uniqueSplit(s, mask, res);
        return res;
    }
};