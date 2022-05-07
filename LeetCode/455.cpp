class Solution {
public:
    int findContentChildren(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int res = 0;
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); bi++) {
            if (a[ai] <= b[bi]) {
                ai++;
                res++;
            }
        }
        
        return res;
    }
};