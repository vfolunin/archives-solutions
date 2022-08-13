class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
            cout << items[i][0] << " " << items[i][1] << endl;
        }
        
        vector<int> res(queries.size());
        
        for (int i = 0; i < res.size(); i++) {
            vector<int> query = { queries[i] + 1 };
            auto it = lower_bound(items.begin(), items.end(), query);
            if (it != items.begin())
                res[i] = (*prev(it))[1];
        }
        
        return res;
    }
};