class Solution {
public:
    long long maxAlternatingSum(vector<int> &a) {
        sort(a.begin(), a.end(), [](int lhs, int rhs) {
            return abs(lhs) < abs(rhs);
        });

        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res += (i < a.size() / 2 ? -1LL : 1LL) * a[i] * a[i];
        return res;
    }
};