class SubrectangleQueries {
    vector<vector<int>> &a;
    
public:
    SubrectangleQueries(vector<vector<int>> &a) : a(a) {}
    
    void updateSubrectangle(int y1, int x1, int y2, int x2, int newValue) {
        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                a[y][x] = newValue;        
    }
    
    int getValue(int y, int x) {
        return a[y][x];
    }
};