class Solution {
    inline static const vector<int> DY = { -1, 0, 1, 0 };
    inline static const vector<int> DX = { 0, 1, 0, -1 };
    
    int rec(vector<string> &a, int n, int catY, int catX, int mouseY, int mouseX, int maxCatStep, int maxMouseStep,
            vector<vector<vector<vector<vector<int>>>>> &memo) {
        int &res = memo[n][catY][catX][mouseY][mouseX];
        if (res)
            return res;
        
        if (n % 2) {
            if (catY == mouseY && catX == mouseX || a[catY][catX] == 'F' || n >= 100)
                return res = 1;
            if (a[mouseY][mouseX] == 'F')
                return res = 2;
            
            for (int d = 0; d < DY.size(); d++) {
                for (int step = 0; step <= maxCatStep; step++) {
                    int ty = catY + DY[d] * step;
                    int tx = catX + DX[d] * step;
                    
                    if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#') {
                        if (rec(a, n + 1, ty, tx, mouseY, mouseX, maxCatStep, maxMouseStep, memo) == 2)
                            return res = 1;
                    } else {
                        break;
                    }
                }
            }
        } else {
            if (a[mouseY][mouseX] == 'F')
                return res = 1;
            if (catY == mouseY && catX == mouseX || a[catY][catX] == 'F' || n >= 100)
                return res = 2;
            
            for (int d = 0; d < DY.size(); d++) {
                for (int step = 0; step <= maxMouseStep; step++) {
                    int ty = mouseY + DY[d] * step;
                    int tx = mouseX + DX[d] * step;
                    
                    if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#') {
                        if (rec(a, n + 1, catY, catX, ty, tx, maxCatStep, maxMouseStep, memo) == 2)
                            return res = 1;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return res = 2;
    }
    
public:
    bool canMouseWin(vector<string> &a, int maxCatStep, int maxMouseStep) {
        int catY, catX, mouseY, mouseX;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == 'C') {
                    catY = y;
                    catX = x;
                } else if (a[y][x] == 'M') {
                    mouseY = y;
                    mouseX = x;
                }
            }
        }
        
        vector<vector<vector<vector<vector<int>>>>> memo(101, 
            vector<vector<vector<vector<int>>>>(a.size(),
            vector<vector<vector<int>>>(a[0].size(), vector<vector<int>>(a.size(), vector<int>(a[0].size())))));
        
        return rec(a, 0, catY, catX, mouseY, mouseX, maxCatStep, maxMouseStep, memo) == 1;
    }
};