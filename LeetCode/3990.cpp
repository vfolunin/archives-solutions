class Solution {
public:
    vector<string> createGrid(int pathCount) {
        vector<string> a(20, string(20, '#'));

        for (int y = 0; y < a.size(); y++) {
            fill(a[y].begin() + y / 2, a[y].begin() + y / 2 + 2, '.');
            a[y].back() = '.';
        }
        
        for (int y = 0; y < a.size(); y += 2) {
            fill(a[y].begin() + y / 2 + 2, a[y].end() - 2, '.');
            if (pathCount & (1 << (y / 2)))
                a[y][a.size() - 2] = '.';
        }

        return a;
    }
};