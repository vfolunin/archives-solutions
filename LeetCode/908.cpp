class Solution {
public:
    int smallestRangeI(vector<int> &a, int k) {
        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        return max(*maxIt - *minIt - 2 * k, 0);
    }
};