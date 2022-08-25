class Solution {
public:
    long long minimumRemoval(vector<int> &a) {
        sort(a.begin(), a.end());
        
        long long res = 1e18;
        
        long long lSum = 0, rSum = accumulate(a.begin(), a.end(), 0LL);        
        for (int i = 0; i < a.size(); i++) {
            rSum -= a[i];
            res = min<long long>(res, lSum + rSum - a[i] * (a.size() - 1LL - i));
            lSum += a[i];
        }
        
        return res;
    }
};