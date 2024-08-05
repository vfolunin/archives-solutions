class neighborSum {
    vector<int> aSum, dSum;
public:
    neighborSum(vector<vector<int>> &a) :
        aSum(a.size() * a.size()), dSum(a.size() * a.size()) {
        vector<int> ady = { -1, 0, 1, 0 };
        vector<int> adx = { 0, 1, 0, -1 };
        vector<int> ddy = { -1, -1, 1, 1 };
        vector<int> ddx = { -1, 1, 1, -1 };

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                for (int d = 0; d < ady.size(); d++) {
                    int aty = y + ady[d];
                    int atx = x + adx[d];
                    if (0 <= aty && aty < a.size() && 0 <= atx && atx < a.size())
                        aSum[a[y][x]] += a[aty][atx];

                    int dty = y + ddy[d];
                    int dtx = x + ddx[d];
                    if (0 <= dty && dty < a.size() && 0 <= dtx && dtx < a.size())
                        dSum[a[y][x]] += a[dty][dtx];
                }
            }
        }
    }
    
    int adjacentSum(int value) {
        return aSum[value];
    }
    
    int diagonalSum(int value) {
        return dSum[value];
    }
};