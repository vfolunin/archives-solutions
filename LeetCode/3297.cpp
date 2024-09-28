struct Counter {
    vector<int> count;
    int negativeCount = 0;

    Counter(string &s) : count(26) {
        for (char c : s)
            inc(c, -1);
    }

    void inc(char c, int delta) {
        negativeCount -= count[c - 'a'] < 0;
        count[c - 'a'] += delta;
        negativeCount += count[c - 'a'] < 0;
    }
};

class Solution {
public:
    long long validSubstringCount(string &a, string &b) {
        Counter counter(b);
        long long res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.inc(a[r], 1);
            while (!counter.negativeCount)
                counter.inc(a[l++], -1);
            res += l;
        }

        return res;
    }
}; 