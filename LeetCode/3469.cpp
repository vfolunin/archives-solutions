class Solution {
    int rec(vector<int> &a, int i, int from, vector<vector<int>> &memo) {
        int &res = memo[i][from];
        if (res != -1)
            return res;
        
        if (from + 1 >= a.size())
            return res = from >= a.size() ? a[i] : max(a[i], a[from]);

        return res = min({
            max(a[i], a[from]) + rec(a, from + 1, from + 2, memo),
            max(a[i], a[from + 1]) + rec(a, from, from + 2, memo),
            max(a[from], a[from + 1]) + rec(a, i, from + 2, memo)
        });
    }

public:
    int minCost(vector<int> &a) {
        vector<vector<int>> memo(a.size(), vector<int>(a.size() + 2, -1));
        return rec(a, 0, 1, memo);
    }
};