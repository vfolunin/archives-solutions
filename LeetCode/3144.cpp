struct Counter {
    vector<int> count;

    Counter() : count(26) {}

    void add(char c) {
        count[c - 'a']++;
    }

    bool isBalanced() {
        int minValue = 1e9, maxValue = 0;
        for (int value : count) {
            if (value && minValue > value)
                minValue = value;
            if (maxValue < value)
                maxValue = value;
        }
        return minValue == maxValue;
    }
};

class Solution {
public:
    int minimumSubstringsInPartition(string &s) {
        vector<int> res(s.size() + 1, 1e9);
        res[0] = 0;

        for (int size = 1; size <= s.size(); size++) {
            Counter counter;
            for (int partSize = 1; partSize <= size; partSize++) {
                counter.add(s[size - partSize]);
                if (counter.isBalanced())
                    res[size] = min(res[size], res[size - partSize] + 1);
            }
        }

        return res.back();
    }
};