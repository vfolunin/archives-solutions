class Solution {
public:
    long long maxSpending(vector<vector<int>> &a) {
        set<pair<int, int>> values;
        for (int i = 0; i < a.size(); i++)
            values.insert({ a[i].back(), i });
        
        long long res = 0;
        for (int i = 1; !values.empty(); i++) {
            auto [value, j] = *values.begin();
            values.erase(values.begin());

            res += 1LL * i * value;

            a[j].pop_back();
            if (!a[j].empty())
                values.insert({ a[j].back(), j });
        }

        return res;
    }
};