class Solution {
public:
    int maxPotholes(string &s, int limit) {
        vector<int> rows;

        int row = 0;
        for (char c : s) {
            if (c == 'x') {
                row++;
            } else if (row) {
                rows.push_back(row);
                row = 0;
            }
        }
        if (row)
            rows.push_back(row);

        sort(rows.begin(), rows.end());
        int res = 0;
        
        while (!rows.empty()) {
            if (limit >= rows.back() + 1) {
                limit -= rows.back() + 1;
                res += rows.back();
                rows.pop_back();
            } else {
                res += max(limit - 1, 0);
                break;
            }
        }

        return res;
    }
};