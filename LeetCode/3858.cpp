class Solution {
public:
    int minimumOR(vector<vector<int>> &a) {
        int res = (1 << 20) - 1;
        for (int bit = 19; bit >= 0; bit--) {
            bool canBeZeroInCol = 1;

            for (int y = 0; y < a.size(); y++) {
                bool canBeZeroInRow = 0;
                for (int value : a[y])
                    canBeZeroInRow |= (value & res) == value && !(value & (1 << bit));
                canBeZeroInCol &= canBeZeroInRow;
            }

            if (canBeZeroInCol)
                res ^= 1 << bit;
        }
        return res;
    }
};