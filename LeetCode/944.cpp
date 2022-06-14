class Solution {
public:
    int minDeletionSize(vector<string> &a) {
        int res = 0;
        for (int col = 0; col < a[0].size(); col++) {
            bool ordered = 1;
            for (int row = 1; ordered && row < a.size(); row++)
                ordered &= a[row - 1][col] <= a[row][col];
            res += !ordered;
        }
        return res;
    }
};