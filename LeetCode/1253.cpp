class Solution {
public:
    vector<vector<int>> reconstructMatrix(int row0Sum, int row1Sum, vector<int> &colSum) {
        vector<vector<int>> res(2, vector<int>(colSum.size()));
        
        for (int i = 0; i < colSum.size(); i++) {
            if (colSum[i] == 2) {
                res[0][i] = res[1][i] = 1;
                row0Sum--;
                row1Sum--;
            } else if (colSum[i] == 1) {
                if (row0Sum >= row1Sum) {
                    res[0][i] = 1;
                    row0Sum--;
                } else {
                    res[1][i] = 1;
                    row1Sum--;
                }
            }
        }
        
        if (!row0Sum && !row1Sum)
            return res;
        else
            return {};
    }
};