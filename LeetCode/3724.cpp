class Solution {
public:
    long long minOperations(vector<int> &a, vector<int> &b) {
        long long res = 0, add = 1e18;
        for (int i = 0; i < a.size(); i++) {
            res += abs(a[i] - b[i]);
            if (a[i] <= b.back() && b.back() <= b[i] || b[i] <= b.back() && b.back() <= a[i])
                add = 1;
            else
                add = min({ add, 1LL + abs(a[i] - b.back()), 1LL + abs(b[i] - b.back()) });
        }
        return res + add;
    }
};