class Solution {
    bool can(vector<int> &a, int k, int dist) {
        int last = -1e9;
        for (int x : a) {
            if (last + dist <= x) {
                last = x;
                k--;
            }
        }
        return k <= 0;
    }

public:
    int maximumTastiness(vector<int> &a, int k) {
        sort(a.begin(), a.end());

        int l = 0, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, k, m))
                l = m;
            else
                r = m;
        }
        
        return l;
    }
};