class Solution {
public:
    int maximumProduct(vector<int> &a) {
        sort(a.begin(), a.end());
        int res = a[a.size() - 3] * a[a.size() - 2] * a[a.size() - 1];
        res = max(res, a[0] * a[1] * a[a.size() - 1]);
        return res;
    }
};