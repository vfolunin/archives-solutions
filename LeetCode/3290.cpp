class Solution {
public:
    long long maxScore(vector<int> &a, vector<int> &b) {
        vector<long long> l1(b.size());
        l1[0] = 1LL * a[0] * b[0];
        for (int i = 1; i < b.size(); i++)
            l1[i] = max(l1[i - 1], 1LL * a[0] * b[i]);
        
        vector<long long> l2(b.size());
        l2[1] = l1[0] + 1LL * a[1] * b[1];
        for (int i = 2; i < b.size(); i++)
            l2[i] = max(l2[i - 1], l1[i - 1] + 1LL * a[1] * b[i]);
        
        vector<long long> r1(b.size());
        r1[b.size() - 1] = 1LL * a[3] * b[b.size() - 1];
        for (int i = b.size() - 2; i >= 0; i--)
            r1[i] = max(r1[i + 1], 1LL * a[3] * b[i]);
        
        vector<long long> r2(b.size());
        r2[b.size() - 2] = r1[b.size() - 1] + 1LL * a[2] * b[b.size() - 2];
        for (int i = b.size() - 3; i >= 0; i--)
            r2[i] = max(r2[i + 1], r1[i + 1] + 1LL * a[2] * b[i]);
        
        long long res = -1e18;
        for (int i = 1; i + 2 < b.size(); i++)
            res = max(res, l2[i] + r2[i + 1]);
        return res;
    }
};