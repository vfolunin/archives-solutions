class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> res(h, vector<int>(w));
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                unordered_set<int> s1;
                for (int d = 1; y - d >= 0 && x - d >= 0; d++)
                    s1.insert(a[y - d][x - d]);
                
                unordered_set<int> s2;
                for (int d = 1; y + d < h && x + d < w; d++)
                    s2.insert(a[y + d][x + d]);
                
                res[y][x] = abs((int)s1.size() - (int)s2.size());
            }
        }
        
        return res;
    }
};