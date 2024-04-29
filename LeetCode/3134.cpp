struct Counter {
    vector<int> count;
    int distinct = 0;

    Counter() : count(1e5 + 1) {}

    void add(int value, int delta) {
        distinct -= count[value] > 0;
        count[value] += delta;
        distinct += count[value] > 0;
    }
};

class Solution {
    bool can(vector<int> &a, int m) {
        Counter counter;
        long long segmentCount = 0;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (counter.distinct > m)
                counter.add(a[l++], -1);
            
            segmentCount += r - l + 1;
        }

        return segmentCount * 2 >= a.size() * (a.size() + 1) / 2;
    }

public:
    int medianOfUniquenessArray(vector<int> &a) {
        int l = 0, r = 1;
        while (!can(a, r))
            r *= 2;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};