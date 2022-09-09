class Solution {
    long long sum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
    long long avg(vector<long long> &p, int l, int r) {
        return sum(p, l, r) / (r - l + 1);
    }
    
    long long avgDiff(vector<long long> &p, int k) {
        return abs(avg(p, 0, k - 1) - avg(p, k, p.size() - 1));
    }
    
public:
    int minimumAverageDifference(vector<int> &a) {        
        vector<long long> p(a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());
        
        long long resDiff = avg(p, 0, p.size() - 1);
        int res = p.size() - 1;
        
        for (int k = 1; k < a.size(); k++) {
            long long diff = avgDiff(p, k);
            if (resDiff > diff || resDiff == diff && res > k - 1) {
                resDiff = diff;
                res = k - 1;
            }
        }
        
        return res;
    }
};