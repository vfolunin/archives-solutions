class Solution {
public:
    bool canMakeSubsequence(string &a, string &b) {
        if (a.size() > b.size())
            return 0;
        if (a.size() == 1)
            return 1;
        
        vector<int> l(a.size(), b.size());
        for (int ai = 0, bi = 0; bi < b.size(); bi++)
            if (a[ai] == b[bi])
                l[ai++] = bi;

        if (l[l.size() - 1] < b.size() || l[l.size() - 2] < b.size() - 1)
            return 1;
        
        vector<int> r(a.size(), -1);
        for (int ai = a.size() - 1, bi = b.size() - 1; bi >= 0; bi--)
            if (a[ai] == b[bi])
                r[ai--] = bi;

        if (r[0] >= 0 || r[1] >= 1)
            return 1;

        for (int i = 1; i + 1 < a.size(); i++)
            if (l[i - 1] + 1 < r[i + 1])
                return 1;
        
        return 0;
    }
};