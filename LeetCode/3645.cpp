class Solution {
public:
    long long maxTotal(vector<int> &a, vector<int> &limit) {
        unordered_map<int, vector<int>> values;
        for (int i = 0; i < a.size(); i++)
            values[limit[i]].push_back(a[i]);

        long long res = 0;
        for (auto &[limit, values] : values) {
            sort(values.rbegin(), values.rend());
            for (int i = 0; i < values.size() && i < limit; i++)
                res += values[i];
        }
        return res;
    }
};