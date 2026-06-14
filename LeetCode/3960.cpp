struct Counter {
    unordered_map<int, int> count;
    map<int, int> counts;

    void add(int value, int delta) {
        if (count[value] && !--counts[count[value]])
            counts.erase(counts.find(count[value]));
        count[value] += delta;
        counts[count[value]]++;
    }

    bool isGood() {
        return counts.size() == 1 && counts.begin()->second == 1 ||
               counts.size() == 2 && counts.begin()->first * 2 == prev(counts.end())->first;
    }
};

class Solution {
public:
    int getLength(vector<int> &a) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            Counter counter;
            for (int r = l; r < a.size(); r++) {
                counter.add(a[r], 1);
                if (counter.isGood())
                    res = max(res, r - l + 1);
            }
        }
        return res;
    }
};