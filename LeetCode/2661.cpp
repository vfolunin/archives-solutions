class Solution {
public:
    int firstCompleteIndex(vector<int> &a, vector<vector<int>> &b) {
        vector<int> row(a.size()), col(a.size());
        for (int y = 0; y < b.size(); y++) {
            for (int x = 0; x < b[0].size(); x++) {
                row[b[y][x] - 1] = y;
                col[b[y][x] - 1] = x;
            }
        }
        
        vector<int> rowCount(a.size()), colCount(a.size());
        for (int i = 0; i < a.size(); i++)
            if (++rowCount[row[a[i] - 1]] == b[0].size() || ++colCount[col[a[i] - 1]] == b.size())
                return i;
        return -1;
    }
};