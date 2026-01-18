class Solution {
public:
    int maxCapacity(vector<int> &price, vector<int> &bonus, int limit) {
        int res = 0;
        for (int i = 0; i < price.size(); i++)
            if (price[i] < limit)
                res = max(res, bonus[i]);

        vector<int> order(price.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int l, int r) {
            return price[l] < price[r];
        });

        multiset<int> bonusSet(bonus.begin(), bonus.end());
        for (int l = 0, r = order.size() - 1; l < r; l++) {
            bonusSet.erase(bonusSet.find(bonus[order[l]]));
            while (l < r && price[order[l]] + price[order[r]] >= limit) {
                bonusSet.erase(bonusSet.find(bonus[order[r]]));
                r--;
            }
            if (l < r)
                res = max(res, bonus[order[l]] + *prev(bonusSet.end()));
        }
        return res;
    }
};