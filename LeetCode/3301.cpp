class Solution {
public:
    long long maximumTotalSum(vector<int> &a) {
        sort(a.begin(), a.end());
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            a[i] = min(a[i], a[i + 1] - 1);
            if (!a[i])
                return -1;
        }
        return accumulate(a.begin(), a.end(), 0LL);
    }
};