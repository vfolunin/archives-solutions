class Solution {
public:
    vector<int> reverseSubarrays(vector<int> &a, int partCount) {
        int partSize = a.size() / partCount;
        for (int l = 0, r = partSize; l < a.size(); l += partSize, r += partSize)
            reverse(a.begin() + l, a.begin() + r);
        return a;
    }
};