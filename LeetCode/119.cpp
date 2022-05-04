class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prevRow, row = { 1 };
        for (int i = 0; i < rowIndex; i++) {
            prevRow.swap(row);
            row.resize(prevRow.size() + 1);
            row.front() = row.back() = 1;
            for (int j = 1; j < prevRow.size(); j++)
                row[j] = prevRow[j - 1] + prevRow[j];
        }
        return row;
    }
};