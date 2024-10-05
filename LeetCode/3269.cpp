class Solution {
    int getBigger(int value, bool parity) {
        return value + 1 + (value % 2 == parity);
    }
    
public:
    int minLargest(vector<int> &a, vector<int> &b) {
        vector<vector<int>> res(a.size() + 1, vector<int>(b.size() + 1, 1e9));
        res[0][0] = 0;

        for (int size = 1; size <= a.size() + b.size(); size++) {
            for (int aSize = 0, bSize = size - aSize; aSize <= size; aSize++, bSize--) {
                if (1 <= aSize && aSize <= a.size() && 0 <= bSize && bSize <= b.size())
                    res[aSize][bSize] = min(res[aSize][bSize], getBigger(res[aSize - 1][bSize], a[aSize - 1]));
                if (0 <= aSize && aSize <= a.size() && 1 <= bSize && bSize <= b.size())
                    res[aSize][bSize] = min(res[aSize][bSize], getBigger(res[aSize][bSize - 1], b[bSize - 1]));
            }
        }

        return res[a.size()][b.size()];
    }
};