class Solution {
public:
    bool isMajorityElement(vector<int> &a, int target) {
        auto [lIt, rIt] = equal_range(a.begin(), a.end(), target);
        return (rIt - lIt) * 2 > a.size();
    }
};