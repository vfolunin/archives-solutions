class Solution {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        vector<int> factorCount(1e5 + 1);
        int minPrice = 1e9;
        for (vector<int> &item : items) {
            factorCount[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }
        
        vector<int> factorProfit(factorCount.size());
        for (int factor = 1; factor < factorCount.size(); factor++)
            for (int product = factor; product < factorCount.size(); product += factor)
                factorProfit[factor] += factorCount[product];
        
        vector<pair<int, int>> pairs;
        for (vector<int> &item : items)
            pairs.push_back({ item[1], factorProfit[item[0]] - 1 });
        sort(pairs.begin(), pairs.end());

        int res = 0;
        for (auto &[price, usages] : pairs) {
            if (minPrice * 2 <= price)
                break;
            int count = min(budget / price, usages);
            budget -= count * price;
            res += count * 2;
        }
        res += budget / minPrice;
        return res;
    }
};