class Solution {
public:
    int longestOnes(vector<int> &a, int k) {
        int zeroCount = 0, res = 0;
        for (int l = 0, r = 0; r < a.size(); r++) {
            zeroCount += !a[r];
            while (zeroCount > k)
                zeroCount -= !a[l++];
            res = max(res, r - l + 1);
        }
        return res;
    }
};