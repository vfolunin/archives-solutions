class Solution {
public:
    long long beautifulSubarrays(vector<int> &a) {
        unordered_map<int, int> count = { { 0, 1 } };
        int xorSum = 0;
        long long res = 0;

        for (int value : a) {
            xorSum ^= value;
            res += count[xorSum];
            count[xorSum]++;
        }

        return res;
    }
};