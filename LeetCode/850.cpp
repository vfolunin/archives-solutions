struct Compressor {
    map<int, int> c;
    vector<int> d;
    
    void add(int x) {
        c[x];
    }
    
    void prepare() {
        for (auto &[coord, compressed] : c) {
            compressed = d.size();
            d.push_back(coord);
        }
    }
    
    int size() {
        return d.size();
    }
    
    int compress(int x) {
        return c[x];
    }
    
    int decompress(int x) {
        return d[x];
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        Compressor cy, cx;
        for (vector<int> &rectangle : rectangles) {
            cy.add(rectangle[1]);
            cy.add(rectangle[3]);
            cx.add(rectangle[0]);
            cx.add(rectangle[2]);
        }
        cy.prepare();
        cx.prepare();
        
        vector<vector<int>> a(cy.size(), vector<int>(cx.size()));
        for (vector<int> &rectangle : rectangles)
            for (int y = cy.compress(rectangle[1]); y < cy.compress(rectangle[3]); y++)
                for (int x = cx.compress(rectangle[0]); x < cx.compress(rectangle[2]); x++)
                    a[y][x]++;
        
        long long res = 0;
        for (int y = 0; y + 1 < cy.size(); y++)
            for (int x = 0; x + 1 < cx.size(); x++)
                if (a[y][x])
                    res += 1LL * (cy.decompress(y + 1) - cy.decompress(y)) * (cx.decompress(x + 1) - cx.decompress(x));
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};