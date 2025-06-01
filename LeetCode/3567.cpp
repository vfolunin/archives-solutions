class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &a, int size) {
        vector<vector<int>> res(a.size() - size + 1, vector<int>(a[0].size() - size + 1, 1e9));

        for (int y = 0; y + size <= a.size(); y++) {
            for (int x = 0; x + size <= a[0].size(); x++) {
                vector<int> values;
                for (int dy = 0; dy < size; dy++)
                    for (int dx = 0; dx < size; dx++)
                        values.push_back(a[y + dy][x + dx]);
                
                sort(values.begin(), values.end());
                values.erase(unique(values.begin(), values.end()), values.end());

                for (int i = 1; i < values.size(); i++)
                    res[y][x] = min(res[y][x], values[i] - values[i - 1]);
                
                if (res[y][x] == 1e9)
                    res[y][x] = 0;
            }
        }

        return res;
    }
};