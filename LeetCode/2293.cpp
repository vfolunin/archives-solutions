class Solution {
    int rec(vector<int> &a, int l, int r) {
        if (l == r)
            return a[l];
        
        int m = l + (r - l) / 2;
        int vl = rec(a, l, m);
        int vr = rec(a, m + 1, r);
        
        if (l / (r - l + 1) % 2)
            return max(vl, vr);
        else
            return min(vl, vr);
    }
    
public:
    int minMaxGame(vector<int> &a) {
        return rec(a, 0, a.size() - 1);
    }
};