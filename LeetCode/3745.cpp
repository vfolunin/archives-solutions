class Solution {
public:
    int maximizeExpressionOfThree(vector<int> &a) {
        sort(a.rbegin(), a.rend());
        return a[0] + a[1] - a.back();
    }
};