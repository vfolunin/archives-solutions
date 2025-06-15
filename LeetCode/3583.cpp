class Solution {
public:
    int specialTriplets(vector<int> &a) {
        unordered_map<int, long long> l, r;
        for (int value : a)
            r[value]++;
        
        long long res = 0;
        const long long MOD = 1e9 + 7;
        for (int value : a) {
            r[value]--;
            res = (res + l[value * 2] * r[value * 2]) % MOD;
            l[value]++;
        }
        return res;
    }
};