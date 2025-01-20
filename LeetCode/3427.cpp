class Solution {
public:
    int subarraySum(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += accumulate(a.begin() + max(i - a[i], 0), a.begin() + i + 1, 0);
        return res;
    }
};