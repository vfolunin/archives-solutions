class Solution {
    bool can(vector<int> &a, int need, int size) {
        for (int value : a)
            need -= value / size;
        return need <= 0;
    }

public:
    int maxLength(vector<int> &a, int need) {
        int l = 0, r = 1e5 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, need, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};