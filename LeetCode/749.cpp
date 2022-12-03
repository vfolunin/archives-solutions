class Solution {
    inline static const vector<int> DY = { -1, 0, 1, 0 };
    inline static const vector<int> DX = { 0, 1, 0, -1 };
    
    void dfsThreatening(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, set<pair<int, int>> &threatening) {
        visited[y][x] = 1;
        
        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];
            
            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || a[ty][tx] > 1 || visited[ty][tx])
                continue;
            
            if (!a[ty][tx])
                threatening.insert({ ty, tx });
            else
                dfsThreatening(a, ty, tx, visited, threatening);
        }
    }
    
    pair<pair<int, int>, int> findCcWithMaxThreatening(vector<vector<int>> &a) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        pair<int, int> cell = { -1, -1 };
        int maxThreatening = 0;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == 1 && !visited[y][x]) {
                    set<pair<int, int>> threatening;
                    dfsThreatening(a, y, x, visited, threatening);
                    if (maxThreatening < threatening.size()) {
                        cell = { y, x };
                        maxThreatening = threatening.size();
                    }
                }
            }
        }
        
        return { cell, maxThreatening };
    }
    
    int dfsPerimeter(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
        visited[y][x] = 1;
        int res = 0;
        
        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];
            
            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || a[ty][tx] > 1 || visited[ty][tx])
                continue;
            
            if (!a[ty][tx])
                res++;
            else
                res += dfsPerimeter(a, ty, tx, visited);
        }
        
        return res;
    }
    
    int getPerimeter(vector<vector<int>> &a, int y, int x) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        return dfsPerimeter(a, y, x, visited);
    }
    
    void dfsMark(vector<vector<int>> &a, int y, int x) {
        a[y][x] = 2;
        
        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == 1)
                dfsMark(a, ty, tx);
        }
    }
    
    void dfsPropagate(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
        visited[y][x] = 1;

        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];
            
            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || a[ty][tx] > 1 || visited[ty][tx])
                continue;
            
            if (!a[ty][tx])
                a[ty][tx] = 3;
            else
                dfsPropagate(a, ty, tx, visited);
        }
    }
    
    void propagate(vector<vector<int>> &a) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] == 1 && !visited[y][x])
                    dfsPropagate(a, y, x, visited);
        
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] == 3)
                    a[y][x] = 1;
    }
    
public:
    int containVirus(vector<vector<int>> &a) {
        int res = 0;
        
        while (1) {
            auto [cell, threatening] = findCcWithMaxThreatening(a);
            if (!threatening)
                break;
            
            res += getPerimeter(a, cell.first, cell.second);
            dfsMark(a, cell.first, cell.second);            
            propagate(a);
        }
        
        return res;
    }
};