class Solution {
public:
    int findNonMinOrMax(vector<int> &a) {
        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        for (int value : a)
            if (*minIt != value && *maxIt != value)
                return value;
        return -1;
    }
};