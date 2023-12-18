struct Counter {
    unordered_map<int, int> count;
    multiset<int> counts;

    void add(int value, int delta) {
        if (auto it = counts.find(count[value]); it != counts.end())
            counts.erase(it);
        count[value] += delta;
        counts.insert(count[value]);
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int> &a, int limit) {
        Counter counter;
        int res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);

            while (*prev(counter.counts.end()) > limit) {
                counter.add(a[l], -1);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};