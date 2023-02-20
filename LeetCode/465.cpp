class Solution {
    int rec(vector<int> &a, map<vector<int>, int> &memo) {
        if (memo.count(a))
            return memo[a];
        int &res = memo[a];
        
        if (a.empty())
            return res = 0;
            
        auto [lIt, rIt] = minmax_element(a.begin(), a.end());
        if (!*lIt && !*rIt)
            return res = 0;
        
        res = 1e9;

        int i = 0;
        while (a[i] <= 0)
            i++;

        for (int j = 0; j < a.size(); j++) {
            if (a[j] < 0) {
                int delta = min(a[i], -a[j]);
                a[i] -= delta;
                a[j] += delta;
                res = min(res, 1 + rec(a, memo));
                a[i] += delta;
                a[j] -= delta;
            }
        }

        return res;
    }

public:
    int minTransfers(vector<vector<int>> &edges) {
        unordered_map<int, int> sums;
        for (vector<int> &edge : edges) {
            sums[edge[0]] -= edge[2];
            sums[edge[1]] += edge[2];
        }

        vector<int> a;
        for (auto &[id, sum] : sums)
            if (sum)
                a.push_back(sum);
        
        map<vector<int>, int> memo;
        return rec(a, memo);
    }
};