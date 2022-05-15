class Solution {
public:
    int maxProduct(vector<int> &a) {
        sort(a.begin(), a.end());
        return max((a[0] - 1) * (a[1] - 1), (a[a.size() - 2] - 1) * (a[a.size() - 1] - 1));
    }
};