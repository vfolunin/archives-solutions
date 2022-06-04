class Solution {
    vector<int> col, d1, d2;
    vector<string> board;
    vector<vector<string>> boards;
    
    void rec(int y, int size) {
        if (y == size) {
            boards.push_back(board);
            return;
        }
        
        for (int x = 0; x < size; x++) {
            if (col[x] || d1[y + x] || d2[y - x + size])
                continue;
            
            col[x] = d1[y + x] = d2[y - x + size] = 1;
            board[y][x] = 'Q';
            rec(y + 1, size);
            col[x] = d1[y + x] = d2[y - x + size] = 0;
            board[y][x] = '.';
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int size) {
        col.resize(size);
        d1.resize(size * 2);
        d2.resize(size * 2);
        board.assign(size, string(size, '.'));
        rec(0, size);
        return boards;
    }
};