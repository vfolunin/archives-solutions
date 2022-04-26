class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &a, int h, int w) {
        int h0 = a.size(), w0 = a[0].size();
        if (h0 * w0 != h * w)
            return a;
        
        vector<vector<int>> res(h, vector<int>(w));
        for (int i = 0; i < h * w; i++)
            res[i / w][i % w] = a[i / w0][i % w0];
        return res;
    }
};