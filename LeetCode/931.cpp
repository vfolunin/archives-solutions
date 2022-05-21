class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &a) {
        int size = a.size();
        
        for (int y = 1; y < size; y++) {
            for (int x = 0; x < size; x++) {
                int minValue = a[y - 1][x];
                for (int dx : { -1, 1 })
                    if (0 <= x + dx && x + dx < size && minValue > a[y - 1][x + dx])
                        minValue = a[y - 1][x + dx];
                a[y][x] += minValue;
            }
        }
        
        return *min_element(a.back().begin(), a.back().end());
    }
};