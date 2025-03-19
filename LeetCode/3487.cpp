class Solution {
public:
    int maxSum(vector<int> &a) {
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (i + 1 == a.size() || a[i] != a[i + 1] && a[i] > 0)
                res += a[i];
        return res;
    }
};