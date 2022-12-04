class Solution {
    bool check(vector<vector<int>> &pos1, vector<vector<int>> &pos2) {
        vector<vector<int>> a(8, vector<int>(8));
        
        for (int i = 0; i < pos1.size(); i++) {
            int y1 = pos1[i][0], x1 = pos1[i][1], y2 = pos2[i][0], x2 = pos2[i][1];
            
            for (int step = 0; step < 8; step++) {
                if (a[y1][x1] & (1 << step))
                    return 0;
                a[y1][x1] |= 1 << step;
                
                y1 += y1 < y2;
                y1 -= y1 > y2;
                x1 += x1 < x2;
                x1 -= x1 > x2;
            }
        }
        
        return 1;
    }
    
    int selectPos2(vector<string> &piece, vector<vector<int>> &pos1, vector<vector<int>> &pos2, int i) {
        if (i == piece.size())
            return check(pos1, pos2);
        
        int res = 0;
        
        vector<int> dy, dx;
        if (piece[i] == "rook") {
            dy = { -1, 0, 1, 0 };
            dx = { 0, 1, 0, -1 };
        } else if (piece[i] == "bishop") {
            dy = { -1, -1, 1, 1 };
            dx = { -1, 1, 1, -1 };
        } else {
            dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
            dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
        }
        
        pos2[i] = pos1[i];
        res += selectPos2(piece, pos1, pos2, i + 1);
        
        for (int d = 0; d < dy.size(); d++) {
            for (int step = 1; 1; step++) {
                pos2[i][0] = pos1[i][0] + dy[d] * step;
                pos2[i][1] = pos1[i][1] + dx[d] * step;
                
                if (0 <= pos2[i][0] && pos2[i][0] < 8 && 0 <= pos2[i][1] && pos2[i][1] < 8)
                    res += selectPos2(piece, pos1, pos2, i + 1);
                else
                    break;
            }
        }
        
        return res;
    }
    
public:
    int countCombinations(vector<string> &piece, vector<vector<int>> &pos1) {
        for (vector<int> &pos : pos1) {
            pos[0]--;
            pos[1]--;
        }
        
        vector<vector<int>> pos2(pos1.size(), vector<int>(2));
        
        return selectPos2(piece, pos1, pos2, 0);
    }
};