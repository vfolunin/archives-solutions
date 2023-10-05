struct Counter {
    vector<int> count;
    int duplicateCount = 0;

    Counter() : count(26) {}

    void add(char c, int delta) {
        duplicateCount -= count[c - 'a'] > 1;
        count[c - 'a'] += delta;
        duplicateCount += count[c - 'a'] > 1;
    }
};

class Solution {
public:
    int numberOfSpecialSubstrings(string &s) {
        Counter counter;
        int res = 0;

        for (int l = 0, r = 0; r < s.size(); r++) {
            counter.add(s[r], 1);
            while (counter.duplicateCount)
                counter.add(s[l++], -1);

            res += r - l + 1;
        }

        return res;
    }
};