class Solution {
public:
    long long subsequenceSumOr(vector<int> &a) {
        long long sum = 0, res = 0;
        for (int value : a) {
            res |= value;
            sum += value;
            res |= sum;
        }
        return res;
    }
};