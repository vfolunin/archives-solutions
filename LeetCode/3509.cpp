class Solution {
public:
    int maxProduct(vector<int> &a, int targetSum, int productLimit) {
        if (abs(targetSum) > 1000)
            return -1;

        vector<unordered_set<int>> sums(2);
        vector<unordered_map<int, set<long long>>> products(2);

        for (int value : a) {
            vector<tuple<int, int, long long>> updates;
            updates.emplace_back(0, value, value);

            for (int type = 0; type < 2; type++) {
                for (int sum : sums[type]) {
                    int nextSum = sum + (type ? value : -value);
                    if (abs(nextSum) > 1000)
                        continue;

                    for (long long product : products[type][sum])
                        updates.emplace_back(type ^ 1, nextSum, product * value);
                }
            }

            for (auto &[type, sum, product] : updates) {
                sums[type].insert(sum);
                products[type][sum].insert(min(product, productLimit + 1LL));
            }
        }

        long long res = -1;
        for (int type = 0; type < 2; type++) {
            set<long long> &p = products[type][targetSum];
            if (auto it = p.upper_bound(productLimit); it != p.begin())
                res = max(res, *prev(it));
        }
        return res;
    }
};