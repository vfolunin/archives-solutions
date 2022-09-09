class Robot {
    int h, w, cell = 0, started = 0;
    vector<vector<int>> cells;
    
public:
    Robot(int w, int h) : h(h), w(w) {
        cells.assign(2 * (h + w - 2), vector<int>(3));
        cells[0] = { 0, 0, 2 };
        
        for (int i = 1; i < cells.size(); i++) {
            int y = cells[i - 1][0], x = cells[i - 1][1], d = cells[i - 1][2];
            int ty, tx;
            
            static vector<int> dy = { 1, 0, -1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
        
            while (1) {
                ty = y + dy[d];
                tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w)
                    break;
                d = (d + 3) % 4;
            }
            
            cells[i] = { ty, tx, d };
        }
    }
    
    void step(int n) {
        cell = (cell + n) % cells.size();
        started = 1;
    }
    
    vector<int> getPos() {
        return { cells[cell][1], cells[cell][0] };
    }
    
    string getDir() {
        static vector<string> dirs = { "North", "East", "South", "West" };
        return dirs[started ? cells[cell][2] : 1];
    }
};