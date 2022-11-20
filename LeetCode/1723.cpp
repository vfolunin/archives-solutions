class Solution {
    bool can(vector<int> &a, int i, vector<int> &sums, int limit) {
        if (i == a.size())
            return 1;
        
        for (int j = 0; j < sums.size(); j++) {
            if (sums[j] + a[i] > limit || j && sums[j - 1] == sums[j])
                continue;
            
            sums[j] += a[i];
            if (can(a, i + 1, sums, limit))
                return 1;
            sums[j] -= a[i];
        }
        
        return 0;
    }
    
    bool can(vector<int> &a, int workerCount, int limit) {
        vector<int> sums(workerCount);
        return can(a, 0, sums, limit);
    }
    
public:
    int minimumTimeRequired(vector<int> &a, int workerCount) {
        sort(a.rbegin(), a.rend());
        
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, workerCount, m))
                r = m;
            else
                l = m;
        }        
        return r;
    }
};