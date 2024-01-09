class Solution {
    bool can(vector<vector<int>> &rows, int size) {
        for (vector<int> &rows : rows) {
            int count = 0;
            for (int row : rows)
                count += max(0, row - size + 1);
            if (count >= 3)
                return count;
        }
        return 0;
    }
public:
    int maximumLength(string &s) {
        vector<vector<int>> rows(26);
        int row = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                rows[s[i - 1] - 'a'].push_back(row);
                row = 1;
            }
        }
        rows[s.back() - 'a'].push_back(row);

        int l = 0, r = 1;
        while (can(rows, r))
            r *= 2;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(rows, m))
                l = m;
            else
                r = m;
        }
        return l ? l : -1;
    }
};