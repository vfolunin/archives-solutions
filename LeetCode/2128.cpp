class Solution {
public:
    bool removeOnes(vector<vector<int>> &a) {
        for (int y = 1; y < a.size(); y++)
            for (int x = 1; x < a[0].size(); x++)
                if ((a[y][x] ^ a[y][0]) != (a[0][x] ^ a[0][0]))
                    return 0;
        return 1;
    }
};