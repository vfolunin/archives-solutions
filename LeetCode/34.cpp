class Solution {
    int from(vector<int> &a, int target) {
        int l = -1, r = a.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] < target)
                l = m;
            else
                r = m;
        }
        return r < a.size() && a[r] == target ? r : -1;
    }
    
    int to(vector<int> &a, int target) {
        int l = -1, r = a.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] <= target)
                l = m;
            else
                r = m;
        }
        return 0 <= l && a[l] == target ? l : -1;
    }
    
public:
    vector<int> searchRange(vector<int> &a, int target) {
        return { from(a, target), to(a, target) };
    }
};