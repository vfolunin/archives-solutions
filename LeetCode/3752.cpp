class Solution {
    bool can(long long l, long long r, long long target) {
        return abs(target) <= (l + r) * (r - l + 1) / 2;
    }

public:
    vector<int> lexSmallestNegatedPerm(int size, long long target) {
        vector<int> res(size);
        for (int value = res.size(), l = 0, r = res.size() - 1; value; value--) {
            if (can(1, value - 1, target + value)) {
                res[l++] = -value;
                target += value;
            } else if (can(1, value - 1, target - value)) {
                res[r--] = value;
                target -= value;
            } else {
                return {};
            }
        }
        return res;
    }
};