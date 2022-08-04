class Solution {
    bool can(vector<int> &a, int bouquetCount, int bouquetSize, int day) {
        int bouquetMade = 0, row = 0;
        for (int d : a) {
            if (d <= day) {
                row++;
                if (row == bouquetSize) {
                    bouquetMade++;
                    row = 0;
                }
            } else {
                row = 0;
            }
        }
        return bouquetMade >= bouquetCount;
    }
    
public:
    int minDays(vector<int> &a, int bouquetCount, int bouquetSize) {
        int l = -1, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, bouquetCount, bouquetSize, m))
                r = m;
            else
                l = m;
        }
        return r != 2e9 ? r : -1;
    }
};