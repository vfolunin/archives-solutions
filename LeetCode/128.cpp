class Solution {
    int getRow(unordered_map<int, int> &row, int value) {
        if (row[value])
            return row[value];
        if (!row.count(value - 1))
            return row[value] = 1;
        return row[value] = getRow(row, value - 1) + 1;
    }
    
public:
    int longestConsecutive(vector<int> &a) {
        unordered_map<int, int> row;
        for (int value : a)
            row[value];
        
        int res = 0;
        for (int value : a)
            res = max(res, getRow(row, value));
        return res;
    }
};