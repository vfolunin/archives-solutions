class Solution {
public:
    int maxProductDifference(vector<int> &a) {
        sort(a.begin(), a.end());
        return a[a.size() - 2] * a[a.size() - 1] - a[0] * a[1];
    }
};