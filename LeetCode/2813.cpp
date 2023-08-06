class Solution {
public:
    long long findMaximumElegance(vector<vector<int>> &items, int k) {        
        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a[0] > b[0];
        });
        
        long long sum = 0;
        unordered_set<int> categories;
        multiset<int> values;

        for (int i = 0; i < k; i++) {
            sum += items[i][0];
            if (!categories.count(items[i][1]))
                categories.insert(items[i][1]);
            else
                values.insert(items[i][0]);
        }
        
        long long res = sum + categories.size() * categories.size();
        
        for (int i = k; i < items.size() && !values.empty(); i++) {
            if (categories.count(items[i][1]))
                continue;
            
            sum += items[i][0] - *values.begin();
            categories.insert(items[i][1]);
            values.erase(values.begin());
            
            res = max<long long>(res, sum + categories.size() * categories.size());
        }
        
        return res;
    }
};