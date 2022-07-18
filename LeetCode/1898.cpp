class Solution {
    bool can(string a, string &b, vector<int> &removable, int m) {
        for (int i = 0; i < m; i++)
            a[removable[i]] = '#';
        a.erase(remove(a.begin(), a.end(), '#'), a.end());
        
        if (a.size() < b.size())
            return 0;
        
        int bi = 0;
        for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
            if (a[ai] == b[bi])
                bi++;
        
        return bi == b.size();
    }
    
public:
    int maximumRemovals(string &a, string &b, vector<int> &removable) {
        int l = 0, r = removable.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, b, removable, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};