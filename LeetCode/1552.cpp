class Solution {
    bool can(vector<int> &a, int dist, int count) {
        int last = a[0], placed = 1;
        for (int &x : a) {
            if (last + dist <= x) {
                last = x;
                placed++;
            }
        }
        return placed >= count;
    }
    
public:
    int maxDistance(vector<int> &a, int count) {
        sort(a.begin(), a.end());
        
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m, count))
                l = m;
            else
                r = m;
        }
        return l;
    }
};