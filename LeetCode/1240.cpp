class Solution {
    void rec(vector<vector<int>> &a, int count, int &minCount) {
        if (count >= minCount)
            return;
        
        int h = a.size(), w = a[0].size();
        
        int cell = 0;
        while (cell < h * w && a[cell / w][cell % w])
            cell++;
        
        if (cell == h * w) {
            minCount = min(minCount, count);
            return;
        }
        
        int y = cell / w, x = cell % w;
        
        for (int size = min(h - y, w - x); size; size--) {
            bool ok = 1;
            for (int dy = 0; ok && dy < size; dy++)
                for (int dx = 0; ok && dx < size; dx++)
                    ok &= !a[y + dy][x + dx];
            
            if (!ok)
                continue;
            
            for (int dy = 0; dy < size; dy++)
                for (int dx = 0; dx < size; dx++)
                    a[y + dy][x + dx] = 1;
            
            rec(a, count + 1, minCount);
            
            for (int dy = 0; dy < size; dy++)
                for (int dx = 0; dx < size; dx++)
                    a[y + dy][x + dx] = 0;
        }
    }
    
public:
    int tilingRectangle(int h, int w) {
        if (h == w)
            return 1;
        
        if (h > w)
            return tilingRectangle(w, h);
        
        vector<vector<int>> a(h, vector<int>(w));
        int minCount = h * w;
        rec(a, 0, minCount);
        return minCount;
    }
};