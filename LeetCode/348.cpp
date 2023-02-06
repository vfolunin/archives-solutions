class TicTacToe {
    int size;
    vector<vector<int>> row, col;
    vector<int> d1, d2;

public:
    TicTacToe(int size) :
        size(size), row(2, vector<int>(size)), col(2, vector<int>(size)), d1(2), d2(2) {}
    
    int move(int y, int x, int p) {
        p--;

        if (++row[p][y] == size ||
            ++col[p][x] == size ||
            y == x && ++d1[p] == size ||
            y + x == size - 1 && ++d2[p] == size)
            return p + 1;
        
        return 0;
    }
};