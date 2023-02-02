struct Counter {
    vector<int> count;
    int distinctCount = 0, distinctLimit;

    Counter(int distinctLimit) : count(128), distinctLimit(distinctLimit) {}

    void add(char c, int delta) {
        distinctCount -= count[c] > 0;
        count[c] += delta;
        distinctCount += count[c] > 0;
    }

    bool isOk() {
        return distinctCount <= distinctLimit;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int distinctLimit) {
        Counter counter(distinctLimit);
        int res = 0;
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            counter.add(s[r], 1);
            while (!counter.isOk()) {
                counter.add(s[l], -1);
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};