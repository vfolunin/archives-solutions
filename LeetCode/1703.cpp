class Solution {
    long long sum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int minMoves(vector<int> &a, int k) {
        vector<long long> p;
        for (int i = 0; i < a.size(); i++)
            if (a[i])
                p.push_back(i);
        
        partial_sum(p.begin(), p.end(), p.begin());
        
        long long res = 1e18;
        
        for (int l = 0, m = k / 2, r = k - 1; r < p.size(); l++, m++, r++) {
            long long mValue = sum(p, m, m);
            
            long long lCount = m - l + 1;
            long long lSum = mValue * lCount - sum(p, l, m) - lCount * (lCount - 1) / 2;
            long long rCount = r - m;
            long long rSum = sum(p, m + 1, r) - mValue * rCount - rCount * (rCount + 1) / 2;

            res = min(res, lSum + rSum);
        }
        
        return res;
    }
};