class Solution {
public:
    long long maximumHappinessSum(vector<int> &a, int n) {
        sort(a.rbegin(), a.rend());
        long long res = 0;
        for (int i = 0; i < n; i++)
            res += max(a[i] - i, 0);
        return res;
    }
};