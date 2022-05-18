class Solution {
public:
    int oddCells(int h, int w, vector<vector<int>> &indices) {
        vector<int> oddRow(h), oddCol(w);
        for (auto &index : indices) {
            oddRow[index[0]] ^= 1;
            oddCol[index[1]] ^= 1;
        }
        
        int r0 = count(oddRow.begin(), oddRow.end(), 0), r1 = h - r0;
        int c0 = count(oddCol.begin(), oddCol.end(), 0), c1 = w - c0;
        return r0 * c1 + r1 * c0;
    }
};