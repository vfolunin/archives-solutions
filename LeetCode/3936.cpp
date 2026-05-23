class Solution {
public:
    int minimumSwaps(vector<int> &a) {
        int zeroCount = count(a.begin(), a.end(), 0);
        return zeroCount - count(a.end() - zeroCount, a.end(), 0);
    }
};