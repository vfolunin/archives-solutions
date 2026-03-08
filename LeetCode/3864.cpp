class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

    long long getCost(vector<int> &p, int l, int r, int cost1, int cost0) {
        long long sum = getSum(p, l, r);
        return sum ? sum * (r - l + 1) * cost1 : cost0;
    }

    long long rec(vector<int> &p, int l, int r, int cost1, int cost0) {
        long long res = getCost(p, l, r, cost1, cost0);
        if ((r - l + 1) % 2 == 0) {
            int m = l + (r - l) / 2;
            res = min(res, rec(p, l, m, cost1, cost0) + rec(p, m + 1, r, cost1, cost0));
        }
        return res;
    }

public:
    long long minCost(string &s, int cost1, int cost0) {
        vector<int> p(s.size());
        for (int i = 0; i < s.size(); i++)
            p[i] = (s[i] == '1') + (i ? p[i - 1] : 0);
        
        return rec(p, 0, s.size() - 1, cost1, cost0);
    }
};