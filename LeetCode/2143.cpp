class Solution {
public:
    int countSubranges(vector<int> &a, vector<int> &b) {
        const long long MOD = 1e9 + 7;

        unordered_map<int, long long> ways;
        long long res = 0;

        for (int i = 0; i < a.size(); i++) {
            unordered_map<int, long long> nextWays;
            nextWays[a[i]]++;
            nextWays[-b[i]]++;

            for (auto &[sum, count] : ways) {
                nextWays[sum + a[i]] = (nextWays[sum + a[i]] + count) % MOD;
                nextWays[sum - b[i]] = (nextWays[sum - b[i]] + count) % MOD;
            }

            ways.swap(nextWays);
            res = (res + ways[0]) % MOD;
        }

        return res;
    }
};