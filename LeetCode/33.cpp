class Solution {
public:
    int search(vector<int> &a, int target) {
        int l = 0, r = a.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] < a[r])
                r = m;
            else
                l = m;
        }
        int from = a[l] < a[r] ? l : r;
        
        l = 0;
        r = a.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[(from + m) % a.size()] == target)
                return (from + m) % a.size();
            else if (a[(from + m) % a.size()] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};