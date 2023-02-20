struct Counter {
    vector<int> count;
    int needCount, badCount = 0;

    Counter(int needCount) : count(26), needCount(needCount) {}

    void add(char c, int delta) {
        badCount += count[c - 'a'] == 0 || count[c - 'a'] == needCount;
        count[c - 'a'] += delta;
        badCount -= count[c - 'a'] == 0 || count[c - 'a'] == needCount;
    }

    bool isOk() {
        return !badCount;
    }
};

class Solution {
public:
    int equalCountSubstrings(string &s, int needCount) {
        int res = 0;

        int charCount = unordered_set<char>(s.begin(), s.end()).size();

        for (int len = needCount; len <= s.size() && len <= charCount * needCount; len += needCount) {
            Counter counter(needCount);
            for (int i = 0; i < len; i++)
                counter.add(s[i], 1);
            res += counter.isOk();    

            for (int i = len; i < s.size(); i++) {
                counter.add(s[i - len], -1);
                counter.add(s[i], 1);
                res += counter.isOk();
            }
        }

        return res;
    }
};