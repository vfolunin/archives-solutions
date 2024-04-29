struct Counter {
    vector<int> count;
    int targetLetterCount = 0, targetCount;

    Counter(int targetCount) : count(26), targetCount(targetCount) {}

    void add(char c, int delta) {
        targetLetterCount -= count[c - 'a'] == targetCount;
        count[c - 'a'] += delta;
        targetLetterCount += count[c - 'a'] == targetCount;
    }
};

class Solution {
    int countCompleteSubstrings(string &s, int l, int r, int repeatCount) {
        int res = 0;

        for (int letterCount = 1, windowSize = repeatCount; letterCount <= 26 && windowSize <= r - l + 1; letterCount++, windowSize += repeatCount) {
            Counter counter(repeatCount);
            for (int i = l; i < l + windowSize; i++)
                counter.add(s[i], 1);
            res += counter.targetLetterCount == letterCount;

            for (int i = l + windowSize; i <= r; i++) {
                counter.add(s[i], 1);
                counter.add(s[i - windowSize], -1);
                res += counter.targetLetterCount == letterCount;
            }
        }

        return res;
    }

public:
    int countCompleteSubstrings(string &s, int repeatCount) {
        int l = 0, res = 0;
        for (int r = 0; r + 1 < s.size(); r++) {
            if (abs(s[r] - s[r + 1]) > 2) {
                res += countCompleteSubstrings(s, l, r, repeatCount);
                l = r + 1;
            }
        }
        res += countCompleteSubstrings(s, l, s.size() - 1, repeatCount);
        return res;
    }
};