struct Counter {
    unordered_map<int, int> count;
    int distinctSum = 0;

    void add(int value, int delta) {
        if (count[value])
            distinctSum -= value;
        count[value] += delta;
        if (count[value])
            distinctSum += value;
    }
};

class Solution {
public:
    int minLength(vector<int> &a, int threshold) {
        Counter counter;
        int res = 1e9;

        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);

            while (counter.distinctSum >= threshold) {
                res = min(res, r - l + 1);
                counter.add(a[l++], -1);
            }
        }

        return res != 1e9 ? res : -1;
    }
};