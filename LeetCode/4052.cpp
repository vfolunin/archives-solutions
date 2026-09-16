class Solution {
public:
    vector<vector<int>> cyclicShift(int size, vector<vector<int>> &a, vector<int> &rowShift, vector<int> &colShift) {
        vector<vector<int>> res = a;
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                res[y][x] = a[y][(x + rowShift[y]) % size];
    
        res.swap(a);
        for (int x = 0; x < size; x++)
            for (int y = 0; y < size; y++)
                res[y][x] = a[(y + colShift[x]) % size][x];

        return res;
    }
};