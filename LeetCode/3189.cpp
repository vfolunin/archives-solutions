class Solution {
public:
    int minMoves(vector<vector<int>> &rooks) {
        int res = 0;

        sort(rooks.begin(), rooks.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < rooks.size(); i++)
            res += abs(rooks[i][0] - i);
        
        sort(rooks.begin(), rooks.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        for (int i = 0; i < rooks.size(); i++)
            res += abs(rooks[i][1] - i);
        
        return res;
    }
};