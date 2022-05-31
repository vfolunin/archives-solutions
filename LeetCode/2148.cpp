class Solution {
public:
    int countElements(vector<int> &a) {
        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        
        int res = a.size() - count(a.begin(), a.end(), *minIt);
        if (*minIt != *maxIt)
            res -= count(a.begin(), a.end(), *maxIt);
        
        return res;
    }
};