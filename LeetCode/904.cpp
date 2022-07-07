struct Counter {
    vector<int> count;
    int nonZeroCount = 0;

    Counter() : count(1e5 + 1) {}

    void add(int i, int delta) {
        nonZeroCount -= count[i] > 0;
        count[i] += delta;
        nonZeroCount += count[i] > 0;
    }

    bool isOk() {
        return nonZeroCount <= 2;
    }
};

class Solution {
public:
    int totalFruit(vector<int> &a) {
        Counter counter;
        int res = 0;
        
        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            while (!counter.isOk()) {
                counter.add(a[l], -1);
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};