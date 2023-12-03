class Solution {
    int getMaxRow(vector<int> &a) {
        sort(a.begin(), a.end());

        int curRow = 1, maxRow = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] + 1 == a[i])
                curRow++;
            else
                curRow = 1;
            maxRow = max(maxRow, curRow);
        }

        return maxRow;
    }

public:
    int maximizeSquareHoleArea(int aSize, int bSize, vector<int> &a, vector<int> &b) {
        int row = min(getMaxRow(a), getMaxRow(b)) + 1;
        return row * row;
    }
};