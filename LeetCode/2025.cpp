class Solution {
public:
    int waysToPartition(vector<int> &a, int k) {
        vector<long long> l = { a.begin(), a.end() };
        partial_sum(l.begin(), l.end(), l.begin());
        
        vector<long long> r = { a.begin(), a.end() };
        partial_sum(r.rbegin(), r.rend(), r.rbegin());
        
        unordered_map<long long, int> lCount, rCount;
        for (int i = 0; i + 1 < a.size(); i++)
            rCount[l[i] - r[i + 1]]++;
        
        int res = rCount[0];
        
        for (int i = 0; i < a.size(); i++) {
            long long delta = k - a[i];
            res = max(res, lCount[delta] + rCount[-delta]);
            
            if (i + 1 < a.size()) {
                lCount[l[i] - r[i + 1]]++;            
                rCount[l[i] - r[i + 1]]--;
            }
        }
        
        return res;
    }
};