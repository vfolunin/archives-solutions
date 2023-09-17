class Solution {
public:
    long long countInterestingSubarrays(vector<int> &a, int mod, int targetValue) {       
        int sum = 0;
        unordered_map<int, int> count = { { 0, 1 } };
        long long res = 0;

        for (int value : a) {
            sum = (sum + (value % mod == targetValue)) % mod;
            res += count[(sum - targetValue + mod) % mod];
            count[sum]++;
        }

        return res;
    }
};