class Solution {
public:
    vector<string> createGrid(int h, int w) {
        vector<string> res(h, string(w, '#'));
        res[0] = string(w, '.');
        for (string &row : res)
            row.back() = '.';
        return res;
    }
};