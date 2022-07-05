class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> count;
        int maxCount = 0;
        
        for (int i = 0; i + minSize <= s.size(); i++) {
            string part = s.substr(i, minSize);
            if (unordered_set(part.begin(), part.end()).size() <= maxLetters)
                maxCount = max(maxCount, ++count[part]);
        }
        
        return maxCount;
    }
};