class Solution {
public:
    int absDifference(vector<int> &a, int count) {
        sort(a.begin(), a.end());
        return abs(accumulate(a.begin(), a.begin() + count, 0) - accumulate(a.end() - count, a.end(), 0));
    }
};