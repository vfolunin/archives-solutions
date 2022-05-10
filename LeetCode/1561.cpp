class Solution {
public:
    int maxCoins(vector<int> &a) {
        sort(a.begin(), a.end());
        int n = a.size() / 3, res = 0;
        for (int i = 0; i < n; i++)
            res += a[n + i * 2];
        return res;
    }
};