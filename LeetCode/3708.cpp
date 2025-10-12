class Solution {
public:
    int longestSubarray(vector<int> &a) {
        int res = 2, cur = 2;
        for (int i = 2; i < a.size(); i++) {
            if (a[i - 2] + a[i - 1] == a[i])
                cur++;
            else
                cur = 2;
            res = max(res, cur);
        }
        return res;
    }
};