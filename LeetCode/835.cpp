class Solution {
public:
    int largestOverlap(vector<vector<int>> &a, vector<vector<int>> &b) {
        int size = a.size(), res = 0;
        
        for (int dy = -size + 1; dy < size; dy++) {
            for (int dx = -size + 1; dx < size; dx++) {
                int overlap = 0;
                
                for (int ay = 0; ay < size; ay++) {
                    int by = ay + dy;
                    for (int ax = 0; ax < size; ax++) {
                        int bx = ax + dx;
                        overlap += a[ay][ax] && 0 <= by && by < size && 0 <= bx && bx < size && b[by][bx];
                    }
                }
                
                res = max(res, overlap);
            }
        }
        
        return res;
    }
};