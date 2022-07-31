class Solution {
    bool can(vector<int> &a, int opLimit, int target) {
        int ops = 0;
        for (int value : a)
            ops += (value - 1) / target;
        return ops <= opLimit;
    }
    
public:
    int minimumSize(vector<int> &a, int opLimit) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, opLimit, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};