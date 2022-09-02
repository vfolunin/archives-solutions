class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &a) {
        if (is_sorted(a.begin(), a.end()))
            return 0;
        
        map<int, int> l;
        l[a[0]] = 1;
        for (int i = 1; a[i - 1] <= a[i]; i++)
            l[a[i]] = i + 1;
        
        map<int, int> r;
        r[a.back()] = 1;
        for (int i = a.size() - 2; a[i] <= a[i + 1]; i--)
            r[a[i]] = a.size() - i;
        
        int res = a.size() - r.begin()->second;
        
        for (auto &[value, lCount] : l) {
            auto it = r.lower_bound(value);
            if (it != r.end()) {
                int rCount = it->second;
                res = min<int>(res, a.size() - lCount - rCount);
            } else {
                res = min<int>(res, a.size() - lCount);
            }
        }
        
        return res;
    }
};