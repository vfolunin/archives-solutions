class Solution {
public:
    int minMoves2(vector<int> &a) {
        sort(a.begin(), a.end());
        
        long long l = 0, r = 0;
        for (int value : a)
            r += value;
        
        long long res = 1e18;
        for (long long i = 0; i < a.size(); i++) {
            res = min<long long>(res, i * a[i] - l + r - (a.size() - i) * a[i]);
            l += a[i];
            r -= a[i];
        }
        
        return res;
    }
};