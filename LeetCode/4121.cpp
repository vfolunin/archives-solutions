class Solution {
public:
    long long minCost(vector<int> &a) {
        long long res = 1e18;
        for (int l = 0, r = 0; r < a.size(); r++) {
            if (a[l] != a[r])
                l = r;
            
            if ((l || r) && (l + 1 < a.size() || r + 1 < a.size()))
                res = min<long long>(res, a[r] * (a.size() - (r - l + 1)));
        }
        return res;
    }
};