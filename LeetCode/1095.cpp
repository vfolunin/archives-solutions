class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int l = 0, r = a.length() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a.get(m) < a.get(m + 1))
                l = m;
            else
                r = m;
        }
        int top = r;
        
        l = 0;
        r = top;
        while (l <= r) {
            int m = l + (r - l) / 2, value = a.get(m);
            if (value == target)
                return m;
            else if (value < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        l = top;
        r = a.length() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2, value = a.get(m);
            if (value == target)
                return m;
            else if (value > target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return -1;
    }
};