class Solution {
public:
    long long maxProduct(vector<int> &a) {
        sort(a.begin(), a.end());

        return max({ abs(1LL * a[0] * a[1]), abs(1LL * a[0] * a.back()), abs(1LL * a[a.size() - 2] * a.back()) }) * 1e5;
    }
};