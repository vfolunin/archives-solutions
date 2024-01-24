class Solution {
public:
    long long incremovableSubarrayCount(vector<int> &a) {
        int l = 0;
        while (l + 1 < a.size() && a[l] < a[l + 1])
            l++;
        
        if (l == a.size() - 1)
            return a.size() * (a.size() + 1) / 2;
        
        int r = a.size() - 1;
        while (r - 1 >= 0 && a[r - 1] < a[r])
            r--;
        
        long long res = 1 + a.size() - r;
        for (int il = 0, ir = r; il <= l; il++) {
            while (ir < a.size() && a[il] >= a[ir])
                ir++;
            res += 1 + a.size() - ir;
        }
        return res;
    }
};