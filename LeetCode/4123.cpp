class Solution {
public:
    long long minCost(vector<int> &a) {
        vector<long long> minValue = { 0, (long long)1e18 };
        for (int i = 1; i + 1 < a.size(); i++) {
            vector<long long> newMinValue = { min(minValue[0], minValue[1] + a[i]), min(minValue[1], minValue[0] + a[i]) };
            minValue.swap(newMinValue);
        }
        return a.front() + minValue[0] + a.back();
    }
};