class Solution {
public:
    long long gcdSum(vector<int> &a) {
        vector<int> g = a;

        for (int i = 1; i < a.size(); i++) {
            a[i] = max(a[i], a[i - 1]);
            g[i] = gcd(g[i], a[i]);
        }

        sort(g.begin(), g.end());

        long long res = 0;
        for (int l = 0, r = g.size() - 1; l < r; l++, r--)
            res += gcd(g[l], g[r]);
        return res;
    }
};