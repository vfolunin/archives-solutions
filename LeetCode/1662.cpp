class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &a, vector<string> &b) {
        int ai = 0, aj = 0;
        int bi = 0, bj = 0;
        
        while (ai < a.size() && bi < b.size() && a[ai][aj] == b[bi][bj]) {
            if (++aj == a[ai].size()) {
                ++ai;
                aj = 0;
            }
            if (++bj == b[bi].size()) {
                ++bi;
                bj = 0;
            }
        }
        
        return ai == a.size() && bi == b.size();
    }
};