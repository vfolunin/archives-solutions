class Solution {
public:
    int maxNumberOfFamilies(int h, vector<vector<int>> &reserved) {
        unordered_map<int, vector<int>> rows;
        for (vector<int> &seat : reserved) {
            if (!rows.count(seat[0] - 1))
                rows[seat[0] - 1].resize(10);
            rows[seat[0] - 1][seat[1] - 1] = 1;
        }
        
        int res = (h - rows.size()) * 2;
        
        for (auto &[y, row] : rows) {
            if (!count(row.begin() + 1, row.begin() + 9, 1))
                res += 2;
            else if (!count(row.begin() + 1, row.begin() + 5, 1) ||
                     !count(row.begin() + 3, row.begin() + 7, 1) ||
                     !count(row.begin() + 5, row.begin() + 9, 1))
                res++;
        }
        
        return res;
    }
};