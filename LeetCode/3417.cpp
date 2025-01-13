class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>> &a) {
        vector<int> res;
        for (int y = 0; y < a.size(); y++) {
            if (y % 2 == 0) {
                for (int x = 0; x < a[0].size(); x++)
                    if ((y + x) % 2 == 0)
                        res.push_back(a[y][x]);
            } else {
                for (int x = a[0].size() - 1; x >= 0; x--)
                    if ((y + x) % 2 == 0)
                        res.push_back(a[y][x]);
            }
        }
        return res;
    }
};