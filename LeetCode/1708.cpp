class Solution {
public:
    vector<int> largestSubarray(vector<int> &a, int width) {
        auto it = max_element(a.begin(), a.end() - width + 1);
        return { it, it + width };
    }
};