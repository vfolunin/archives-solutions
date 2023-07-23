class Solution {
    bool can(vector<int> &a, int groups) {
        int need = 0;
        for (int i = 0; i < a.size(); i++) {
            need += max(groups - i, 0);
            need -= min(need, a[i]);
        }
        return !need;
    }

public:
    int maxIncreasingGroups(vector<int> &a) {
        sort(a.rbegin(), a.rend());
        
        int l = 0, r = a.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                l = m;
            else
                r = m;
        }

        return l;
    }
};