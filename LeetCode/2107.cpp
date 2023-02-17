struct Counter {
    unordered_map<int, int> count;

    void add(int i, int delta) {
        count[i] += delta;
        if (!count[i])
            count.erase(i);
    }

    int uniqueCount() {
        return count.size();
    }
};

class Solution {
public:
    int shareCandies(vector<int> &a, int width) {
        Counter counter;
        for (int i = width; i < a.size(); i++)
            counter.add(a[i], 1);
        int res = counter.uniqueCount();

        for (int i = 0; i + width < a.size(); i++) {
            counter.add(a[i], 1);
            counter.add(a[i + width], -1);
            res = max(res, counter.uniqueCount());
        }
        return res;
    }
};