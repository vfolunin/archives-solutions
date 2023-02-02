class Solution {
public:
    int twoSumLessThanK(vector<int> &a, int limit) {
        int res = -1;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (a[i] + a[j] < limit)
                    res = max(res, a[i] + a[j]);
        return res;
    }
};