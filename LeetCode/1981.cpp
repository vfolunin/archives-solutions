class Solution {
public:
    int minimizeTheDifference(vector<vector<int>> &a, int target) {
        int h = a.size(), w = a[0].size();
        
        bitset<5000> can;
        can[0] = 1;

        for (int y = 0; y < h; y++) {
            bitset<5000> nextCan;
            
            for (int x = 0; x < w; x++)
                nextCan |= can << a[y][x];
            
            can = nextCan;
        }
        
        int res = 1e9;
        for (int i = 0; i < can.size(); i++)
            if (can[i])
                res = min(res, abs(i - target));
        return res;
    }
};