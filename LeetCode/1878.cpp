class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        set<int> res;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                res.insert(a[y][x]);
                if (res.size() > 3)
                    res.erase(res.begin());
                
                for (int size = 1; y + 2 * size < h && 0 <= x - size && x + size < w; size++) {
                    int sum = a[y][x] + a[y + 2 * size][x];
                    sum += a[y + size][x - size] + a[y + size][x + size];
                    
                    for (int i = 1; i < size; i++) {
                        sum += a[y + i][x - i] + a[y + i][x + i];
                        sum += a[y + size + i][x - size + i] + a[y + size + i][x + size - i];
                    }
                    
                    res.insert(sum);
                    if (res.size() > 3)
                        res.erase(res.begin());
                }
            }
        }
        
        return { res.rbegin(), res.rend() };
    }
};