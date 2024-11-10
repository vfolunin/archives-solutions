class Solution {
public:
    int maxIncreasingSubarrays(vector<int> &a) {
        vector<int> len(a.size(), 1);
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] < a[i])
                len[i] = len[i - 1] + 1;
        
        int res = 1;
        for (int i = 1; i < a.size(); i++) {
            res = max(res, len[i] / 2);
            if (len[i] <= i)
                res = max(res, min(len[i], len[i - len[i]]));
        }
        return res;
    }
};