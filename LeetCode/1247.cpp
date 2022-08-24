class Solution {
public:
    int minimumSwap(string &a, string &b) {
        int xy = 0, yx = 0;
        for (int i = 0; i < a.size(); i++) {
            xy += a[i] == 'x' && b[i] == 'y';
            yx += a[i] == 'y' && b[i] == 'x';
        }
        
        int res = xy / 2 + yx / 2;
        if (xy % 2 && yx % 2)
            res += 2;
        else if (xy % 2 || yx % 2)
            return -1;
        return res;
    }
};