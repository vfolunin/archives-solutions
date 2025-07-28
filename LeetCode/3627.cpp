class Solution {
public:
    long long maximumMedianSum(vector<int> &a) {
        sort(a.begin(), a.end());

        long long res = 0;
        for (int i = a.size() / 3; i < a.size(); i += 2)
            res += a[i];
        return res;
    }
};