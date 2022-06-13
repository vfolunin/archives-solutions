class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &a) {
        for (vector<int> &row : a) {
            reverse(row.begin(), row.end());
            for (int &value : row)
                value ^= 1;
        }
        return a;
    }
};