class Solution {
    struct Pair {
        int a = 0, b = 0;
        
        Pair operator + (const Pair &that) const {
            return { a + that.a, b + that.b };
        }
        
        Pair operator - (const Pair &that) const {
            return { a - that.a, b - that.b };
        }
        
        int getMin() const {
            return min(a, b);
        }
    };
    
    
public:
    int maxTrailingZeros(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<Pair>> p(h, vector<Pair>(w));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                while (a[y][x] % 2 == 0) {
                    p[y][x].a++;
                    a[y][x] /= 2;
                }
                while (a[y][x] % 5 == 0) {
                    p[y][x].b++;
                    a[y][x] /= 5;
                }
            }
        }
        
        auto u = p, l = p;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y)
                    u[y][x] = u[y][x] + u[y - 1][x];
                if (x)
                    l[y][x] = l[y][x] + l[y][x - 1];
            }
        }
        
        auto d = p, r = p;
        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                if (y < h - 1)
                    d[y][x] = d[y][x] + d[y + 1][x];
                if (x < w - 1)
                    r[y][x] = r[y][x] + r[y][x + 1];
            }
        }
        
        int res = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                res = max(res, (u[y][x] + r[y][x] - p[y][x]).getMin());
                res = max(res, (u[y][x] + d[y][x] - p[y][x]).getMin());
                res = max(res, (u[y][x] + l[y][x] - p[y][x]).getMin());
                res = max(res, (r[y][x] + d[y][x] - p[y][x]).getMin());
                res = max(res, (r[y][x] + l[y][x] - p[y][x]).getMin());
                res = max(res, (d[y][x] + l[y][x] - p[y][x]).getMin());
            }
        }
        return res;
    }
};