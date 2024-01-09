class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>> &a) {
        int maxD2 = 0, maxArea = 0;
        for (vector<int> &row : a) {
            int d2 = row[0] * row[0] + row[1] * row[1];
            int area = row[0] * row[1];
            if (maxD2 < d2 || maxD2 == d2 && maxArea < area) {
                maxD2 = d2;
                maxArea = area;
            }
        }
        return maxArea;
    }
};