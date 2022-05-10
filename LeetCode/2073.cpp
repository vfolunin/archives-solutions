class Solution {
public:
    int timeRequiredToBuy(vector<int> &a, int k) {
        int res = 0;
        for (int i = 0; i <= k; i++)
            res += min(a[i], a[k]);
        for (int i = k + 1; i < a.size(); i++)
            res += min(a[i], a[k] - 1);
        return res;
    }
};