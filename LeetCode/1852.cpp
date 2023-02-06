struct Counter {
    unordered_map<int, int> count;
    int distinctCount = 0;

    void add(int value, int delta) {
        distinctCount -= count[value] > 0;
        count[value] += delta;
        distinctCount += count[value] > 0;
    }
};

class Solution {
public:
    vector<int> distinctNumbers(vector<int> &a, int width) {
        Counter counter;
        for (int i = 0; i < width; i++)
            counter.add(a[i], 1);
        vector<int> res = { counter.distinctCount };

        for (int i = width; i < a.size(); i++) {
            counter.add(a[i - width], -1);
            counter.add(a[i], 1);
            res.push_back(counter.distinctCount);
        }

        return res;
    }
};