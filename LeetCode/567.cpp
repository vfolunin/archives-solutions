class Solution {
    unordered_map<char, int> count;
    int nonZeroCount = 0;

    void add(char c, int delta) {
        nonZeroCount -= count[c] != 0;
        count[c] += delta;
        nonZeroCount += count[c] != 0;
    }
    
public:
    bool checkInclusion(const string &pattern, const string &text) {
        if (pattern.size() > text.size())
            return 0;
        
        for (int i = 0; i < pattern.size(); i++) {
            add(pattern[i], 1);
            add(text[i], -1);
        }
        
        if (!nonZeroCount)
            return 1;
        
        for (int l = 0, r = pattern.size(); r < text.size(); l++, r++) {
            add(text[l], 1);
            add(text[r], -1);

            if (!nonZeroCount)
                return 1;
        }
        
        return 0;
    }
};