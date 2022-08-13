class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>> &a, string word) {
        int h = a.size(), w = a[0].size();
        
        for (int yl = 0, yr = word.size(); yl < h; yl++, yr++) {
            for (int xl = 0, xr = word.size(); xl < w; xl++, xr++) {
                if (a[yl][xl] == '#')
                    continue;
                
                if ((!yl || a[yl - 1][xl] == '#') && (yr == h || yr < h && a[yr][xl] == '#')) {
                    bool ok1 = 1, ok2 = 1;
                    for (int i = 0; i < word.size(); i++) {
                        ok1 &= a[yl + i][xl] == word[i] || a[yl + i][xl] == ' ';
                        ok2 &= a[yl + i][xl] == word[word.size() - 1 - i] || a[yl + i][xl] == ' ';
                    }
                    if (ok1 || ok2)
                        return 1;
                }
                
                if ((!xl || a[yl][xl - 1] == '#') && (xr == w || xr < w && a[yl][xr] == '#')) {
                    bool ok1 = 1, ok2 = 1;
                    for (int i = 0; i < word.size(); i++) {
                        ok1 &= a[yl][xl + i] == word[i] || a[yl][xl + i] == ' ';
                        ok2 &= a[yl][xl + i] == word[word.size() - 1 - i] || a[yl][xl + i] == ' ';
                    }
                    if (ok1 || ok2)
                        return 1;
                }
            }
        }
        
        return 0;
    }
};