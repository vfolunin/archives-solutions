class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &a) {
        vector<vector<int>> row(9, vector<int>(9));
        vector<vector<int>> col(9, vector<int>(9));
        vector<vector<int>> block(9, vector<int>(9));
        
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                if (a[y][x] == '.')
                    continue;
                
                int b = y / 3 * 3 + x / 3, val = a[y][x] - '1';
                if (row[y][val] || col[x][val] || block[b][val])
                    return 0;
                row[y][val] = col[x][val] = block[b][val] = 1;
            }
        }
        
        return 1;
    }
};