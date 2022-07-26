class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &a) {
        map<vector<int>, int> count;
        int maxCount = 0;
        
        for (vector<int> &row : a) {
            maxCount = max(maxCount, ++count[row]);
            
            for (int &value : row)
                value ^= 1;            
            maxCount = max(maxCount, ++count[row]);
        }
        
        return maxCount;
    }
};