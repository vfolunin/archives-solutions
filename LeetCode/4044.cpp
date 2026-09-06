class Solution {
public:
    int countGoodRotations(vector<int> &a) {
        long long sum = accumulate(a.begin(), a.end(), 0LL);

        long long curSum = accumulate(a.begin(), a.begin() + a.size() / 2, 0LL);
        int res = curSum * 2 > sum;

        for (int l = 0, r = a.size() / 2; l + 1 < a.size(); l++, r = (r + 1) % a.size()) {
            curSum += a[r] - a[l];
            res += curSum * 2 > sum;
        }

        return res;
    }
};