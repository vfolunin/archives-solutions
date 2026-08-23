struct Counter {
    unordered_map<int, int> count;

    void add(int value, int delta) {
        for (long long d = 2; d * d <= value; d++) {
            if (value % d == 0) {
                if (!(count[d] += delta))
                    count.erase(d);
                while (value % d == 0)
                    value /= d;
            }
        }
        if (value != 1 && !(count[value] += delta))
            count.erase(value);
    }

    int size() {
        return count.size();
    }
};

class Solution {
public:
    int longestSubarray(vector<int> &a, int limit) {
        Counter counter;
        int res = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (counter.size() > limit)
                counter.add(a[l++], -1);
            
            res = max(res, r - l + 1);
        }

        return res;
    }
};