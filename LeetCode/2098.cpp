class Solution {
public:
    long long largestEvenSum(vector<int> &a, int k) {
        vector<vector<int>> values(2);
        for (int value : a)
            values[value % 2].push_back(value);
        
        for (vector<int> &values : values)
            sort(values.begin(), values.end());
        
        long long res = 0;
        while (k) {
            if (k >= 2 && values[1].size() >= 2 && (values[0].size() <= 1 ||
                values[0][values[0].size() - 2] + values[0][values[0].size() - 1] <=
                values[1][values[1].size() - 2] + values[1][values[1].size() - 1])) {
                res += values[1].back();
                values[1].pop_back();
                res += values[1].back();
                values[1].pop_back();
                k -= 2;
            } else if (!values[0].empty()) {
                res += values[0].back();
                values[0].pop_back();
                k--;
            } else {
                return -1;
            }
        }
        return res;
    }
};