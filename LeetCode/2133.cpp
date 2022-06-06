class Solution {
public:
    bool checkValid(vector<vector<int>> &a) {
        vector<vector<int>> row(a.size(), vector<int>(a.size()));
        vector<vector<int>> col(a.size(), vector<int>(a.size()));
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                if (row[y][a[y][x] - 1] || col[x][a[y][x] - 1])
                    return 0;
                row[y][a[y][x] - 1] = col[x][a[y][x] - 1] = 1;
            }
        }
        
        return 1;
    }
};