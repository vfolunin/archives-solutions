class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> values = { a, b, c };
        int res = 1e9;
        for (int i = 0; i < 10; i++) {
            sort(values.begin(), values.end());
            res = min(res, values[2] - values[0]);
            values[2] = values[0] + values[1];
        }
        return res;
    }
};