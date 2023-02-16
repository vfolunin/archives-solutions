class Solution {
public:
    vector<int> sortTransformedArray(vector<int> &values, int a, int b, int c) {
        for (int &value : values)
            value = a * value * value + b * value + c;
        sort(values.begin(), values.end());
        return values;
    }
};