struct Counter {
    vector<int> count;
    int distinctCount = 0;

    Counter() : count(26) {}

    void add(char c, int delta) {
        distinctCount -= count[c - 'a'] > 0;
        count[c - 'a'] += delta;
        distinctCount += count[c - 'a'] > 0;
    }
};

class Solution {
public:
    int numKLenSubstrNoRepeats(string &s, int width) {
        if (s.size() < width)
            return 0;

        Counter counter;
        for (int i = 0; i < width; i++)
            counter.add(s[i], 1);
        int res = counter.distinctCount == width;

        for (int i = width; i < s.size(); i++) {
            counter.add(s[i - width], -1);
            counter.add(s[i], 1);
            res += counter.distinctCount == width;
        }

        return res;
    }
};