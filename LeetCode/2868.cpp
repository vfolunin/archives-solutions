class Solution {
public:
    bool canAliceWin(vector<string> &a, vector<string> &b) {
        for (int ai = 0, bi = 0; ai < a.size(); ) {
            while (bi < b.size() && b[bi] <= a[ai])
                bi++;
            if (bi == b.size() || a[ai][0] + 1 < b[bi][0])
                return 1;
              
            while (ai < a.size() && a[ai] <= b[bi])
                ai++;
            if (ai == a.size() || b[bi][0] + 1 < a[ai][0])
                return 0;
        }
        return 0;
    }
};