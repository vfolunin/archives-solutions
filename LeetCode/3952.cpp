class Solution {
public:
    long long maxTotal(vector<int> &a, string &s) {
        vector<int> pos;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                pos.push_back(i);

        if (pos.empty())
            return 0;
        
        vector<vector<long long>> res(pos.size(), vector<long long>(2));
        res[0][0] = a[pos[0]];
        if (pos[0])
            res[0][1] = a[pos[0] - 1];

        for (int i = 1; i < pos.size(); i++) {
            res[i][0] = max(res[i - 1][0], res[i - 1][1]) + a[pos[i]];
            res[i][1] = (pos[i - 1] + 1 < pos[i] ? max(res[i - 1][0], res[i - 1][1]) : res[i - 1][1]) + a[pos[i] - 1];
        }
        return max(res.back()[0], res.back()[1]);
    }
};