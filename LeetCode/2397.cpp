class Solution {
public:
    int maximumRows(vector<vector<int>> &a, int cols) {
        int h = a.size(), w = a[0].size();
        
        string mask(w, '0');
        fill(mask.end() - cols, mask.end(), '1');
        
        int res = 0;
        
        do {
            int covered = 0;
            
            for (vector<int> row : a) {
                for (int x = 0; x < w; x++)
                    if (mask[x] == '1')
                        row[x] = 0;
                
                covered += !count(row.begin(), row.end(), 1);
            }
            
            res = max(res, covered);
        } while (next_permutation(mask.begin(), mask.end()));
        
        return res;
    }
};