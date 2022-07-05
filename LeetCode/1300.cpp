class Solution {
    int getDiff(vector<int> &a, vector<int> &p, int value, int target) {
        int from = lower_bound(a.begin(), a.end(), value) - a.begin();
        int sum = (a.size() - from) * value + (from ? p[from - 1] : 0);
        return abs(sum - target);
    }
    
public:
    int findBestValue(vector<int> &a, int target) {
        sort(a.begin(), a.end());
        
        vector<int> p = a;
        partial_sum(p.begin(), p.end(), p.begin());
        
        int l = -1, r = 1e5;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (getDiff(a, p, m, target) <= getDiff(a, p, m + 1, target))
                r = m;
            else
                l = m;
        }
        return r;
    }
};