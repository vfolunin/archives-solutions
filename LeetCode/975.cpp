class Solution {
    int rec(vector<vector<int>> &to, int v, int parity, vector<vector<int>> &good) {
        int &res = good[v][parity];
        if (res != -1)
            return res;

        if (v == to.size() - 1)
            return res = 1;

        if (to[v][parity] == -1)
            return res = 0;

        res = 0;
        return res = rec(to, to[v][parity], parity ^ 1, good);
    }

public:
    int oddEvenJumps(vector<int> &a) {
        map<int, int> index;
        vector<vector<int>> to(a.size(), vector<int>(2, -1));

        for (int i = a.size() - 1; i >= 0; i--) {
            if (auto it = index.lower_bound(a[i]); it != index.end())
                to[i][0] = it->second;
            if (auto it = index.upper_bound(a[i]); it != index.begin())
                to[i][1] = prev(it)->second;
            index[a[i]] = i;
        }

        vector<vector<int>> good(a.size(), vector<int>(2, -1));
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += rec(to, i, 0, good);
        return res;
    }
};