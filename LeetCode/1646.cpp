class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> a = { 0, 1 };
        for (int i = 2; i <= n; i++)
            a.push_back(a[i / 2] + (i % 2 ? a[i / 2 + 1] : 0));
        return *max_element(a.begin(), a.begin() + n + 1);
    }
};