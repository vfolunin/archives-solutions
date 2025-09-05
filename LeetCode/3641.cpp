struct Counter {
    unordered_map<int, int> count;
    int repeatingCount = 0;

    void add(int value, int delta) {
        repeatingCount -= count[value] > 1;
        count[value] += delta;
        repeatingCount += count[value] > 1;
    }
};

class Solution {
public:
    int longestSubarray(vector<int> &a, int limit) {
        Counter counter;
        int res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (counter.repeatingCount > limit)
                counter.add(a[l++], -1);
            
            res = max(res, r - l + 1);
        }

        return res;
    }
};