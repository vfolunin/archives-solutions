class Solution {
public:
    int countSpecialSubsequences(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        vector<long long> count(3);
        
        for (int value : a) {
            if (value)
                count[value] = (count[value] * 2 + count[value - 1]) % MOD;
            else
                count[value] = (count[value] * 2 + 1) % MOD;
        }
        
        return count.back();
    }
};