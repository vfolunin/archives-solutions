class TicTacToe {
    int size;
    vector<vector<map<pair<int, int>, int>>> row;

public:
    TicTacToe(int size) :
        size(size), row(3, vector<map<pair<int, int>, int>>(8)) {}
    
    int move(int y, int x, int p) {
        static const vector<int> DY = { -1, -1, -1, 0, 1, 1, 1, 0 };
        static const vector<int> DX = { -1, 0, 1, 1, 1, 0, -1, -1 };

        vector<int> curRow(DY.size(), 1);
        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];
            if (auto it = row[p][d].find({ ty, tx }); it != row[p][d].end())
                curRow[d] += it->second;
        }

        for (int d = 0, rd = DY.size() / 2; d < DY.size(); d++, rd = (rd + 1) % DY.size()) {
            if (curRow[d] + curRow[rd] > size)
                return p;

            row[p][d][{ y, x }] = curRow[d];

            if (curRow[d] > 1) {
                int ty = y + DY[d] * (curRow[d] - 1);
                int tx = x + DX[d] * (curRow[d] - 1);
                row[p][rd][{ ty, tx }] += curRow[rd];
            }
        }

        return 0;
    }
};