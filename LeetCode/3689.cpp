class Solution {
public:
    long long maxTotalValue(vector<int> &a, long long factor) {
        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        return factor * (*maxIt - *minIt);
    }
};