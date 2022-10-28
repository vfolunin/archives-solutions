class Solution {
public:
    vector<int> gridIllumination(int size, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        set<pair<int, int>> lampSet;
        for (vector<int> &lamp : lamps)
            lampSet.insert({ lamp[0], lamp[1] });
        
        unordered_map<int, int> row, col, d1, d2;
        for (auto &[y, x] : lampSet) {
            row[y]++;
            col[x]++;
            d1[y + x]++;
            d2[y - x]++;
        }
        
        vector<int> res(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int y = queries[i][0];
            int x = queries[i][1];
            
            res[i] = row[y] || col[x] || d1[y + x] || d2[y - x];
                        
            for (int ty = y - 1; ty <= y + 1; ty++) {
                for (int tx = x - 1; tx <= x + 1; tx++) {
                    if (auto it = lampSet.find({ ty, tx }); it != lampSet.end()) {
                        lampSet.erase(it);
                        row[ty]--;
                        col[tx]--;
                        d1[ty + tx]--;
                        d2[ty - tx]--;
                    }
                }
            }
        }
        
        return res;
    }
};