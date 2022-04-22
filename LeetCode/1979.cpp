class Solution {
public:
    int findGCD(vector<int> &a) {
        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        return gcd(*minIt, *maxIt);
    }
};