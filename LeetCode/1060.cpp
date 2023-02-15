class Solution {
public:
    int missingElement(vector<int> &a, int k) {
        for (int i = 1; i < a.size(); i++) {
            if (k > a[i] - a[i - 1] - 1)
                k -= a[i] - a[i - 1] - 1;
            else
                return a[i - 1] + k;
        }
        return a.back() + k;
    }
};