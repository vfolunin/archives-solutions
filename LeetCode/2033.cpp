class Solution {
public:
    int minOperations(vector<vector<int>> &a, int delta) {
        unordered_set<int> remainders;
        vector<int> values;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                remainders.insert(a[y][x] % delta);
                values.push_back(a[y][x]);
            }
        }
        
        if (remainders.size() > 1)
            return -1;
        
        nth_element(values.begin(), values.begin() + (values.size() - 1) / 2, values.end());
        int median = values[(values.size() - 1) / 2];
        int res = 0;
        
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                res += abs(a[y][x] - median) / delta;
        
        return res;
    }
};