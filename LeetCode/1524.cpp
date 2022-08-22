class Solution {
public:
    int numOfSubarrays(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> count = { 1, 0 };
        long long sum = 0, res = 0;
        
        for (int value : a) {
            sum += value;
            res = (res + count[sum % 2 ^ 1]) % MOD;
            count[sum % 2]++;
        }
        
        return res;
    }
};