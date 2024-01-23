class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int> &a, int limit) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < a.size(); i++)
            pairs.push_back({ a[i], i });
        sort(pairs.begin(), pairs.end());

        vector<int> values, indexes;
        for (auto &[value, index] : pairs) {
            if (values.empty() || value - values.back() <= limit) {
                values.push_back(value);
                indexes.push_back(index);
            } else {
                sort(indexes.begin(), indexes.end());
                for (int i = 0; i < indexes.size(); i++)
                    a[indexes[i]] = values[i];
                
                values = { value };
                indexes = { index };
            }
        }
        sort(indexes.begin(), indexes.end());
        for (int i = 0; i < indexes.size(); i++)
            a[indexes[i]] = values[i];

        return a;
    }
};