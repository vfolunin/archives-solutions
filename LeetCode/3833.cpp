class Solution {
public:
    int dominantIndices(vector<int> &a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            sum -= a[i];
            res += a[i] * (a.size() - 1 - i) > sum;
        }
        return res;
    }
};