class Solution {
public:
    long long maxSum(vector<vector<int>> &a, vector<int> &rowLimit, int countLimit) {
        vector<pair<int, int>> pairs;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                pairs.push_back({ a[y][x], y });
        
        sort(pairs.rbegin(), pairs.rend());

        long long res = 0;
        for (auto &[value, y] : pairs) {
            if (countLimit && rowLimit[y]) {
                res += value;
                countLimit--;
                rowLimit[y]--;
            }
        }

        return res;
    }
};