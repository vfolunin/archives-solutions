class Solution {
public:
    int minCost(vector<vector<int>> &a) {
        vector can(a.size(), vector(a[0].size(), vector<int>(1024)));
        can[0][0][a[0][0]] = 1;

        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                for (int value = 0; value < 1024; value++)
                    can[y][x][value] |= y && can[y - 1][x][value ^ a[y][x]] || x && can[y][x - 1][value ^ a[y][x]];
        
        int res = 0;
        while (!can.back().back()[res])
            res++;
        return res;
    }
};