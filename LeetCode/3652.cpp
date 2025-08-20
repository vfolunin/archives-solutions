class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    long long maxProfit(vector<int> &price, vector<int> &op, int width) {
        vector<long long> pPrice(price.begin(), price.end());
        partial_sum(pPrice.begin(), pPrice.end(), pPrice.begin());

        vector<long long> pCost(price.size());
        for (int i = 0; i < pCost.size(); i++)
            pCost[i] = price[i] * op[i] + (i ? pCost[i - 1] : 0);
        
        long long res = pCost.back();
        for (int l = 0, m = width / 2, r = width - 1; r < pCost.size(); l++, m++, r++)
            res = max(res, getSum(pCost, 0, l - 1) + getSum(pPrice, m, r) + getSum(pCost, r + 1, pCost.size() - 1));
        return res;
    }
};