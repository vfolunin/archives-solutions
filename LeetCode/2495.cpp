class Solution {
public:
    long long evenProduct(vector<int> &a) {
        long long res = 0;
        for (int l = 0, r = 0; r < a.size(); l++) {
            while (r < l || r < a.size() && a[r] % 2)
                r++;
            res += a.size() - r;
        }
        return res;
    }
};