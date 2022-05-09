class Solution {
public:
    int maxProduct(vector<int> &a) {
        int minProduct = 1, maxProduct = 1, res = a[0];
        for (int value : a) {
            int minP = min(value, min(value * minProduct, value * maxProduct));
            int maxP = max(value, max(value * minProduct, value * maxProduct));
            minProduct = minP;
            maxProduct = maxP;
            res = max(res, maxProduct);
        }
        return res;
    }
};