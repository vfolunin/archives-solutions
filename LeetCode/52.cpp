class Solution {
    vector<int> col, d1, d2;
    
    int rec(int y, int size) {
        if (y == size)
            return 1;
        
        int res = 0;
        
        for (int x = 0; x < size; x++) {
            if (col[x] || d1[y + x] || d2[y - x + size])
                continue;
            
            col[x] = d1[y + x] = d2[y - x + size] = 1;
            res += rec(y + 1, size);
            col[x] = d1[y + x] = d2[y - x + size] = 0;
        }
        
        return res;
    }
    
public:
    int totalNQueens(int size) {
        col.resize(size);
        d1.resize(size * 2);
        d2.resize(size * 2);
        return rec(0, size);
    }
};