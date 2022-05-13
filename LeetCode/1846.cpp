class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &a) {
        sort(a.begin(), a.end());
        a[0] = 1;
        for (int i = 1; i < a.size(); i++)
            a[i] = min(a[i], a[i - 1] + 1);
        return a.back();
    }
};